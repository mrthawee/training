#include<stdio.h>

int main(void) {
   printf("size of char = %lu\n", sizeof(char));
//   printf("size of byte = %lu\n", sizeof(byte));
   printf("size of short = %lu\n", sizeof(short));
   printf("size of unsigned short = %lu\n", sizeof(unsigned short));
   printf("size of int = %lu\n", sizeof(int));
   printf("size of unsigned int = %lu\n", sizeof(unsigned int));
   printf("size of long = %lu\n", sizeof(long));
   printf("size of long long = %lu\n", sizeof(long long));

   int i=0;
   for (i=65535/2-5; i<65535/2+5; i++) {
      short s = i;
      printf("i=%d s=%d %hx %hi\n", i, s, s, s);
   }

   for (i=-5; i<5; i++) {
      short s = i;
      printf("i=%d s=%d %hx %hi\n", i, s, s, s);
   }

   for (i=65535-5; i<65535+5; i++) {
      short s = i;
      printf("i=%d s=%d %hx %hi\n", i, s, s, s);
   }

   return 0;
}
