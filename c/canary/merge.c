#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct sampleType {
   int   value;
   char  timestamp[20];
} Sample;

Sample samp[6];

#define BUF_SIZE 6
int buf[6];
int rPos=0;
int wPos=0;

#define ALPHA 0.05
#define THRESHOLD 2.0

#define LOUD_VALUE 3000
#define READY  0
#define FOUND  1
int state = READY;

double avg = 0;
int isLogging = 0;
int counter = 0;

char str[1000] = "\0";

void enQ(int d) {
   buf[wPos] = d;
   // overwrite if the queue is full
   if (rPos == (wPos + 1) % BUF_SIZE) {
      rPos = (rPos + 1) % BUF_SIZE; // advance the read position
   }
   wPos = (wPos+1) % BUF_SIZE;
}

/* No use in this context
int deQ(void) {
   int d = buf[rPos];
   rPos = (rPos+1) % BUF_SIZE;
   return d;
}
*/

int isBufFull() {
   return (rPos == (wPos+1) % BUF_SIZE);
}

void ptrQ(char* str) {
   int i,n;
   char tmpStr[20]="\0";
   // the buf before rPos is 'empty', so we can check if it is full
   // so, we use only 'BUF_SIZE - 1' buffers
   n = rPos; // start from the current read position
   for (i=0; i<BUF_SIZE-1; i++) { 
      sprintf(tmpStr,"%d,", buf[n]);
      strcat(str,tmpStr);
      n = (n+1) % BUF_SIZE; // circular the index
   }
   //printf("ptrQ: %s\n", str);
}

void feed(int data, int i, char *timeStamp) {
   char tmpStr[20]="\0";

   enQ(data);
//   avg = (ALPHA * abs(data)) + ((1.0 - ALPHA) * avg); 
   
   if (isLogging == 0) {
//      float ratio = data/avg;

//      if (ratio > THRESHOLD) {
      if ((data >= LOUD_VALUE) && (state == READY)) {
         printf("Found UP @ %d\n", i);
         state = FOUND;

         if (isBufFull()) {
            isLogging = 1;
            // 1. create log string with time stamp
            //sprintf(str,"%s ", "00:00:00.500");
            sprintf(str,"%s ", timeStamp);
            // 2. concat log string with the last 5 samples
            ptrQ(str);

            // 3. continue to log the next 5 samples 
            isLogging = 1;
            // 4. set need more log counter to 5
            counter = 5;
         } 
      } else if ((data < LOUD_VALUE) && (state == FOUND)) {
         //printf("back to Ready\n");
         state = READY;
      }
   } else {
      // write this data to log file
      if (counter > 0) {
         if (counter > 1) 
            sprintf(tmpStr,"%d,",data);
         else
            sprintf(tmpStr,"%d",data);

         strcat(str,tmpStr);
      } else {
         // write to log file
         printf("To File: %s\n", str);
         isLogging = 0;  // ready for the next loud noise
      }
      counter--;
   }
}

void *readSamples(void *arg) {
   int counter;
   FILE *fp;
   short data;

   fp = fopen("test.txt", "r");
   if (!fp) {
      printf("Error: unable to open file.\n");
      exit(-1);
   }

   counter = 0;
   while (fscanf(fp,"%hd",&data) != EOF) {
//      fread(&my_rec, sizeof(struct rec), 1, fp);
//      fscanf(fp,"%d %d %d", &my_rec.x, &my_rec.y, &my_rec.z);
//      printf("%d: x=%d y=%d z=%d\n", counter, my_rec.x, my_rec.y, my_rec.z);

      //printf("%d: x=%hd \n", ++counter, data);

      usleep(50000); // delay 50 msec
      struct timeval tv;
      struct timezone tz;
      struct tm *tm;
      gettimeofday(&tv, &tz);
      tm = localtime(&tv.tv_sec);
      int msec = tv.tv_usec/1000;
      printf("%d:%02d:%02d.%03d found %hd\n", tm->tm_hour, tm->tm_min,
                     tm->tm_sec, msec, data);

      char str[15];
      sprintf(str, "%d:%02d:%02d.%03d", tm->tm_hour, tm->tm_min,
                     tm->tm_sec, msec);

   }

   fclose(fp);
   printf("File is closed ... done.\n");
}


int main(void) {

/*
   int data[1000];
   char timeStamp[20];

   int i;
   for (i=1; i<1000; i++) {
      //if ((i%100 == 0) || (i>200 && i<400))
      if (i%100 == 0)
         data[i] = 4000;
      else
         data[i] = i%10;
   }

   struct timeval tv;
   struct timezone tz;
   struct tm *tm;
   for (i=0; i<1000; i++) {
      gettimeofday(&tv, &tz);
      tm = localtime(&tv.tv_sec);

      sprintf(timeStamp, "%d:%02d:%02d.%06ld", tm->tm_hour, tm->tm_min, tm->tm_sec,
                  tv.tv_usec);
      feed(data[i], i, timeStamp);
      usleep(50000);
//      printf("%d ", data[i]);
   }
   */

   pthread_t tid;

   pthread_attr_t attr;
   pthread_attr_init(&attr);

   pthread_create(&tid, &attr, readSamples, NULL);

   pthread_join(tid, NULL);
   printf("thread is terminated.\n");

}
