#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

   int input = 0;

   if (argc < 2)
      input = 50000;
   else 
      input = atoi(argv[1]);

   printf("input = %d\n", input);

   struct timeval start, end;

   long mtime, seconds, useconds;

   gettimeofday(&start, NULL);
   //usleep(2000);
   usleep(input);
   gettimeofday(&end, NULL);

   seconds = end.tv_sec - start.tv_sec;
   useconds = end.tv_usec - start.tv_usec;

   mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;

   printf("Elapsed time: %ld msecs\n", mtime);

   return 0;
}
