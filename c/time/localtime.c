#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main() {
   struct timeval tv;
   struct timezone tz;
   struct tm *tm;
   gettimeofday(&tv, &tz);
   tm = localtime(&tv.tv_sec);
   printf("Time: %d:%02d:%02d %ld \n", tm->tm_hour, tm->tm_min, tm->tm_sec, tv.tv_usec);
   return 0;
}
