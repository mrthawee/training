#include <stdio.h>

union {
   int i[5];
   short s[10];
} u_x;


void test_union(void) {
   u_x.i[3] = 128; 
   u_x.s[5] = 2;

   int n;
   char *c = (char*)&u_x;
   for (n=0; n<20; n++)
      printf("0x%02x ", c[n]); 
}

main() {
   int arr[5];
   short *s;
   *s = 2;

   arr[3] = 128;
   (short*)&(arr[6]) = *s;

   printf("%d\n", arr[3]);
}
