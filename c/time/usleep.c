#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
   int i=0;
   unsigned int usecs = 1000000;
   for (i=0; i<10; i++) {
      usleep(usecs);
      printf("%ld\n", (long)time(NULL));
   }

   return 0;
}
