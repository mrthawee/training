#include <stdio.h>

/*
   x = x ^ y;
   y = x ^ y; -> y = (x ^ y) ^ y => x ^ (y ^ y) => x ^ 0 => x
   x = x ^ y; -> x = (x ^ y) ^ x => x ^ x ^ y => y
*/
#define SWAP(a, b)  (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

void xorSwap(int *x, int *y) {
   if (x != y) {
      *x = *x ^ *y;
      *y = *x ^ *y;
      *x = *x ^ *y;
   }
}

int main(int argc, char* argv[]) {

   int b1 = 3;
   int b2 = 5;

   int c = b1 ^ b2;
   int d = b2 ^ b1;

   printf("b1=%d  b2=%d\n", b1, b2);

   SWAP(b1, b2);

   printf("b1=%d  b2=%d\n", b1, b2);

   xorSwap(&b1, &b2);

   printf("b1=%d  b2=%d\n", b1, b2);

   return 0;
}
