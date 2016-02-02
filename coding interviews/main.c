#include <stdio.h>
#include <stdlib.h>

int main(void) {
   static int i = 0;

   printf("i=%d\n", i);

   if (i >= 5)
      exit(0);

   i++;

   main();

   return 0;
}
