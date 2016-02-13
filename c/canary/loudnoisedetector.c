/* Loud Noise Detector
 * By: Thawee Techathamnukoool
 * Date: Feb 7, 2016
 *
 * compile : gcc loudnoisedetector.c -o loudnoisedetector -pthread
 *
 * input: "samples.bin" binary file with 16-bit signed interger samples
 * output:"output.txt" text log detected noise
 *
 * Architecture:
 * 2 threads + 1 circular buffer w overwritten (sliding window)
 * - one thread to read file input file with 50 msec interval.  Each sample
 *   is kept in a circular buffer for the last 10 samples.  Each record
 *   in the circular buffer has sample value and its time stamp.
 * - one thread to process each sample read which is read by the other thread
 *   and signalled to process by pthread_cond_t
 *     conc, conp are 2 pthread_cond_t to synchronize the 2 threads.
 *     mutex is used to protect circular buffer when reading and writinng.
 *
 * "loud noise" : defined by the abs(sample value) if greater than THRESHOLD
 *    THRESHOLD is a #define and default to 10000.  When the processing thread
 *    found the absolute of new sample value raise above THRESHOLD, it gets to
 *    DETECTED state.  
 *
 *    state = DETECTED : sample processing thread is set to DETECTED when 
 *       detecting the abs(sample value) > THRESHOLD.  Then it also gets to
 *       logging mode and wait for 5 more samples before logging the output
 *       record to "output.txt"
 *    state = READY : sample processing thread is monitoring for loud noise.
 *       It also sets to READY if it was in DETECTED and new the 
 *       abs(sample value) drops below THRESHOLD
 *
 *  Log record in "output.txt"
 *    Each record has this following format.
 *    <timestamp of sample 1-5>, <sample1-1>, <sample1-2>, ...., <sample1-10>
 *    <timestamp of sample 2-5>, <sample2-1>, <sample2-2>, ...., <sample2-10>
 *    <timestamp of sample 3-5>, <sample3-1>, <sample3-2>, ...., <sample3-10>
 *
 *  No logging if no 10 samples to complete the record.
 *  - detecting noise without 10 samples before detecting shall not be logged.
 *  - detecting noise without 5 more samples following shall not be logged.
 *  No logging for continuous 'loud noise'.  Detector looks for value drop to
 *  under THRESHOLD before logging again.
 *  
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <math.h>

#define THRESHOLD 10000
#define READY 0
#define DETECTED 1

int state = READY;
int counter = 0;  // count # of tailer samples for each log record

// 50 for 50 millisecond timer
#define INTERVAL 50

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conc, conp;  // producer-consumer communication
int flag = 0;               // to synchronize reading samples vs processing samples threads

// file pointer to read 'sample.bin'
FILE *input_fp;   // file pointer for input file "samples.bin"
FILE *output_fp;  // file pointer for output file "output.txt"

#define TIME_STAMP_STRING_LENGTH 13
#define BUF_SIZE 11  // need 11 buf for 10 circular buffer 
int rPos = 0;  // read Position Index
int wPos = 0;  // write Position Index
typedef struct Sample {
   short value;
   char  ts[TIME_STAMP_STRING_LENGTH];  // time stamp when reading this sample
} SampleType;
SampleType buf[BUF_SIZE];

char logTS[TIME_STAMP_STRING_LENGTH]; // buf to create a text log record before writing to output file.

char logRec[1000]; // buf to create a text log record before writing to output file.
int  isLogging = 0;  // internal flag for logging operation

inline int isQFull() {
   return (rPos == (wPos+1) % BUF_SIZE); 
}

/*
 * enQ : adding a Node of Sample(value + timestamp) into the circular queue
 */
void enQ(SampleType d) {
   // Debug: printf("enQ: %d - wPos=%d rPos=%d\n", d.value, wPos, rPos);
   buf[wPos].value = d.value;
   strcpy(buf[wPos].ts, d.ts);

   if (rPos == (wPos+1) % BUF_SIZE) { 
      // Debug: printf("Q is full - overwrite\n");
      rPos = (rPos+1) % BUF_SIZE;
   }

   wPos = (wPos+1) % BUF_SIZE;
}

/*
 * readQ : read value of sample index n from current wPos
 *   NOTE: the latest insertion needs "1" since wPos points to the next to be
 *         writen slot.
 */
short readQ(int nPosBackFromLast) {
   int i = (wPos-nPosBackFromLast + BUF_SIZE) % BUF_SIZE;
//   printf("wPos=%d i=%d : data=%hd\n", wPos, i, buf[i].value);

   return buf[i].value;
}

char* getTSFromQ(int pos) {
   int i = (wPos - pos + BUF_SIZE) % BUF_SIZE;
   return buf[i].ts;
}

/*
 * ptrQ : print queue - utility function to dump queue
 *  
 * in - gobackN : to start from N pos before rPos (to be read index)
 */
void ptrQ(int goBackN) {
   int i,n;
   n = (rPos-goBackN + BUF_SIZE) % BUF_SIZE;
   printf("rPos=%d wPos=%d n=%d : \n\t", rPos, wPos, n);
   for (i=0; i<BUF_SIZE; i++) {
      printf("%hd ", buf[n].value);
      n = (n+1) % BUF_SIZE;
   }
   printf("\n");

   /* uncomment if wanna dump array starting index 0 
   printf("Dump Buf (start from index 0): ");
   for (i=0; i<BUF_SIZE; i++) {
      printf("%hd ", buf[i].value);
   }
   */
}

/*
 * readSample : function to read sample from input file
 */
void readSample(void) {
   if (input_fp == NULL)
      exit(0);

   short data = 0;
   int isEOF;
   isEOF = fread(&data, sizeof(data), 1, input_fp);

   // Exit of end of file.
   if (isEOF == 0) {
      if (input_fp != NULL) {
         fclose(input_fp);
         printf("Done\n");
         input_fp ==NULL;
         exit(0);
      }
   }
   
   // Get timestamp
   struct timeval tv;
   struct timezone tz;
   struct tm *tm;
   gettimeofday(&tv, &tz);
   tm = localtime(&tv.tv_sec);
   int msec = tv.tv_usec/1000;

   char ts[TIME_STAMP_STRING_LENGTH];
   sprintf(ts,"%d:%02d:%02d.%03d", tm->tm_hour, tm->tm_min, tm->tm_sec, msec);
   // Debug: print each sample read and its timestamp
   //printf("%d:%02d:%02d.%03d found %hd\n", tm->tm_hour, tm->tm_min, tm->tm_sec, msec, data);

   // create a Sample node to be put into the circular queue.
   SampleType s;
   s.value = data;
   strcpy(s.ts, ts);

   pthread_mutex_lock(&mutex);
   while (flag != 0)
      pthread_cond_wait(&conp, &mutex);
   flag = 1;
   enQ(s);
   pthread_cond_signal(&conc);
   pthread_mutex_unlock(&mutex);
}

/*
 * readFileTimer : 
 */
void readFileTimer() {
   struct itimerval it_val;

   if (signal(SIGALRM, (void (*)(int))readSample) == SIG_ERR) {
      printf("Error: unable to catch SIGALRM\n");
      pthread_exit(0);
   }

   it_val.it_value.tv_sec = INTERVAL/1000;
   it_val.it_value.tv_usec = (INTERVAL*1000) % 1000000;
   it_val.it_interval = it_val.it_value;

   if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
      printf("Error: calling setitimer() failed!\n");
      pthread_exit(0);
   }

   while(1) {
      pause();
   }
}

/*
 * readSamples : entry function of file reader thread
 */
void *readSamples(void *arg) {
   input_fp = fopen("samples.bin", "rb");
   if (!input_fp) {
      printf("Error: unable to open file.\n");
      exit(-1);
   }

   readFileTimer();
}

/*
 * processSamples : entry function of the sample processor thread
 */
void *processSamples(void *arg) {
   short data;
   FILE *output_fp;
   output_fp = fopen("output.txt", "w");
   if (!output_fp) {
      printf("Error: unable to open output.txt\n");
      exit (-1);
   }

   while (1) {
      // Wait for mutex to process the next data
      pthread_mutex_lock(&mutex);
      while (flag == 0)
         pthread_cond_wait(&conc, &mutex);
      flag = 0;
      data = readQ(1); // read last written one (-1 from curr wPos)
      pthread_cond_signal(&conp);
      pthread_mutex_unlock(&mutex);

      unsigned short us_data = data;

      if (isLogging == 0) {
         if ((abs(data) >= THRESHOLD) && (state == READY) && isQFull()) {
               isLogging = 1;
               counter = 5;
               state = DETECTED;
               strcpy(logTS, getTSFromQ(1)); // get TS from the last buff
         } else if (abs(data) < THRESHOLD) {
            state = READY;
         } 
      } else if (isLogging != 0) {
         if (counter > 0) 
         {
            counter--;
            short d[10]; // temp variables for logging/printing
            if (counter <= 0) { // just in case counter went under 0
               int i;
               pthread_mutex_lock(&mutex); 
               for (i=10; i>0; i--) { // read 10th - 1st pos before rPos
                  d[i-1] = readQ(i);
               }
               pthread_mutex_unlock(&mutex);

               sprintf(logRec,"%s,%hd,%hd,%hd,%hd,%hd,%hd,%hd,%hd,%hd,%hd\n",
                  logTS,d[9],d[8],d[7],d[6],d[5],d[4],d[3],d[2],d[1],d[0]);
               printf("%s", logRec);
               fprintf(output_fp, "%s", logRec);

               isLogging = 0;
               counter = 0;
            }
         }
      }
   }
}

int main(void) {

   pthread_mutex_init(&mutex, NULL);
   pthread_cond_init(&conc, NULL);
   pthread_cond_init(&conp, NULL);

   pthread_t tid;
   pthread_attr_t attr;
   pthread_attr_init(&attr);
   pthread_create(&tid, &attr, readSamples, NULL);

   pthread_t p_tid;
   pthread_attr_t p_attr;
   pthread_attr_init(&p_attr);
   pthread_create(&p_tid, &p_attr, processSamples, NULL);

   pthread_join(tid, NULL);
   pthread_join(p_tid, NULL);

   return 0;
}

