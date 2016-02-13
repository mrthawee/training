#include <stdio.h>

int main(void) {
   short s=0;

   s=-20000;

   unsigned short us = s;
   printf("s=%d us=%d\n", s, us);

   return 0;
}
   
