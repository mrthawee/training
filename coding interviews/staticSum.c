#include <stdio.h>

int staticSum(int n) {
   static int ss = 0;
   ss += n;
   return ss;
}

int main(void) {
   int s = 0;
   for (int i=1; i<=4; i++) {
      s += staticSum(i);
   }

   printf("sum = %d\n", s);

   return 0;
}
