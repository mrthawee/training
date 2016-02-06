#include <stdio.h>
#include <time.h>

int main() {
   time_t rawtime;

   time(&rawtime);
   printf("Current date and time are: %s", ctime(&rawtime));

   return 0;
}
