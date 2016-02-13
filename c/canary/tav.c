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
#define FOUND 1

int state = READY;
int counter = 0;  // count # of tailer samples for each log record

// 50 for 50 millisecond timer
//#define INTERVAL 50
#define INTERVAL 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conc, conp;  // producer-consumer communication
int flag = 0;               // to synchronize reading samples vs processing samples threads

// file pointer to read 'sample.bin'
FILE *input_fp;   // file pointer for input file "samples.bin"
FILE *output_fp;

#define TIME_STAMP_STRING_LENGTH 13
#define BUF_SIZE 11  // need 11 buf for 10 circular buffer 
int rPos = 0;  // read Position Index
int wPos = 0;  // write Position Index
typedef struct Sample {
   short value;
   char  ts[TIME_STAMP_STRING_LENGTH];  // time stamp when reading this sample
} SampleType;
SampleType buf[BUF_SIZE];

char ts[TIME_STAMP_STRING_LENGTH]; // TS to be logged
int isLogging = 0;

inline int isQFull() {
   return (rPos == (wPos+1) % BUF_SIZE); 
}

void enQ(SampleType d) {
//   printf("enQ: %d - wPos=%d rPos=%d\n", d.value, wPos, rPos);
   buf[wPos].value = d.value;
   strcpy(buf[wPos].ts, d.ts);

   //if (rPos == (wPos+1) % BUF_SIZE) {
   if (isQFull()) {
      //printf("Q is full - overwrite\n");
      rPos = (rPos+1) % BUF_SIZE;
   }

   wPos = (wPos+1) % BUF_SIZE;
}

short readQ(int nPosBackFromLast) {
   int i = (wPos-nPosBackFromLast + BUF_SIZE) % BUF_SIZE;
//   printf("wPos=%d i=%d : data=%hd\n", wPos, i, buf[i].value);

   return buf[i].value;
}



char* getTSFromQ(int pos) {
   int i = (wPos - pos + BUF_SIZE) % BUF_SIZE;
   return buf[i].ts;
}

void ptrQ(int goBackN) {
   int i,n;
   n = (rPos-goBackN + BUF_SIZE) % BUF_SIZE;
   printf("rPos=%d wPos=%d n=%d : \n\t", rPos, wPos, n);
   for (i=0; i<BUF_SIZE; i++) {
      printf("%hd ", buf[n].value);
      n = (n+1) % BUF_SIZE;
   }
   printf("\n");

   printf("Dump Buf (start from index 0): ");
   for (i=0; i<BUF_SIZE; i++) {
      printf("%hd ", buf[i].value);
   }
}

void readSample(void) {

   if (input_fp == NULL)
      pthread_exit(0);

   short data = 0;
   int isEOF;
   isEOF = fscanf(input_fp,"%hd",&data);

   if (isEOF == EOF) {
      if (input_fp != NULL) {
         fclose(input_fp);
         printf("EOF : File is closed - done .\n");
         input_fp ==NULL;
       //  pthread_exit(0);
         exit(0);
      }
   }
   
   struct timeval tv;
   struct timezone tz;
   struct tm *tm;
   gettimeofday(&tv, &tz);
   tm = localtime(&tv.tv_sec);
   int msec = tv.tv_usec/1000;

   char ts[TIME_STAMP_STRING_LENGTH];
   sprintf(ts,"%d:%02d:%02d.%03d", tm->tm_hour, tm->tm_min, tm->tm_sec, msec);
//   printf("%d:%02d:%02d.%03d found %hd\n", tm->tm_hour, tm->tm_min, tm->tm_sec, msec, data);

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

void *readSamples(void *arg) {
   input_fp = fopen("samples.bin", "rb");
   if (!input_fp) {
      printf("Error: unable to open file.\n");
      exit(-1);
   }

   readFileTimer();
}

void *processSamples(void *arg) {
   short data;

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
//      printf("Process: found data = %hd -> us=%d\n", data, us_data);

/*
      if (abs(data) > THRESHOLD) {
         strcpy(ts,getTSFromQ(1)); // get TS from the last buff
         printf("Found %d @ %s\n", data,ts);
      }
*/

      if (isLogging == 0) {
         if ((abs(data) >= THRESHOLD) && (state == READY) && isQFull()) {
               isLogging = 1;
               counter = 5;
               state = FOUND;
               strcpy(ts, getTSFromQ(1)); // get TS from the last buff
         } else if (abs(data) < THRESHOLD) {
            state = READY;
         } 
      } else if (isLogging != 0) {
         if (counter > 0) 
         {
            counter--;
            if (counter <= 0) { // just in case counter went under 0
               printf("log: %s: ", ts);
               int i;
               for (i=10; i>0; i--) { // read 10th - 1st pos before rPos
                  short d = readQ(i);
                  printf("%hd ", d);
               }
               printf("\n");
               isLogging = 0;
               counter = 0;
            }
         }
      }
   }
// if (input_fp == NULL)
//    exit(0);

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

   printf("threads are terminated.\n");

   return 0;
}

