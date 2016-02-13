#include <stdio.h>

int main(void) {
   unsigned short u = 0;
   short s = 0;
   int i = 0;

   for (i=0; i<0xFFFF+2; i++) {
      u = i;
      s = i;
      printf("%d %u %d\n", i, u, s);
   }

   return 0;
}
