#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#define BUF_SIZE 6

typedef struct SampleType {
   int   value;
   char  timestamp[15];
} Sample;

Sample buf[BUF_SIZE];

//int buf[6];

int rPos = 0;
int wPos = 0;

//void enQ(int d) {
void enQ(Sample d) {
   printf("enQ: %d - wPos=%d rPos=%d\n", d.value, wPos, rPos);
   buf[wPos].value = d.value;
   strcpy(buf[wPos].timestamp, d.timestamp);

   // if FULL, overwrite.
   if (rPos == (wPos + 1) % BUF_SIZE) {
      printf("Q full.\n");
      rPos = (rPos + 1) % BUF_SIZE;
   }

   wPos = (wPos + 1) % BUF_SIZE;
}

/*
int deQ(void) {
   printf("deQ: wPos=%d rPos=%d ", wPos, rPos);
   int d = buf[rPos];
   rPos = (rPos + 1) % BUF_SIZE;
   printf("d=%d\n", d);
   return d;
}
*/

void ptrQ(void) {
   int i,n;

   printf("rPos = %d  wPos = %d : ", rPos, wPos);
   n = rPos;
   for (i=0; i<BUF_SIZE; i++) {
      //printf("%d ", buf[n]);
      printf("%s - %d ", buf[n].timestamp, buf[n].value);
      n = (n+1) % BUF_SIZE;
   }
   printf("\n");

   printf("Buf: ");
   for (i=0; i<BUF_SIZE; i++) {
      //printf("%d ", buf[i]);
      printf("%s - %d ", buf[i].timestamp, buf[i].value);
   }
   printf("\n");
}

int main(void) {
   int i,n;

   //int data[100];
   Sample data[100];

   for (i=0; i<100; i++) {
      data[i].value = i+1;
   }

   struct timeval  tv;
   struct timezone tz;
   struct tm      *tm;
   int  msec;
   char tsStr[15];

   for (i=0; i<46; i++) {
      gettimeofday(&tv, &tz);
      tm = localtime(&tv.tv_sec);
      msec = tv.tv_usec/1000;

      sprintf(tsStr, "%d:%02d:%02d.%03d", tm->tm_hour, tm->tm_min,
                                           tm->tm_sec, msec);

      strcpy(data[i].timestamp, tsStr);   
      
      enQ(data[i]);

      usleep(50000);
   }

   ptrQ();
}
