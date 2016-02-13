#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

#define INTERVAL 50


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
      printf("%d:%02d:%02d.%06ld found %hd\n", tm->tm_hour, tm->tm_min,
                     tm->tm_sec, tv.tv_usec, data);

   }

   fclose(fp);
   printf("File is closed ... done.\n");
}

int main(void) {

   pthread_t tid;

   pthread_attr_t attr;
   pthread_attr_init(&attr);

   pthread_create(&tid, &attr, readSamples, NULL);

   pthread_join(tid, NULL);
   printf("thread is terminated.\n");

   return 0;
}

