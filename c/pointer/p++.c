#include <stdio.h>

int main(void) {
   int a = 1, b = 3;
   int *pa;
   int *pb;

   pa = &a;
   pb = &b;

   printf("a=%d  b=%d\n", a, b);
   printf("&a=%p  &b=%p\n", &a, &b);
   printf("*pa=%d  *pb=%d\n", *pa, *pb);
   printf("pa=%p  pb=%p\n", pa, pb);
   printf("----\n");


   *pa++ = *pb++;
   /*
   *pa = *pb;
   printf("a=%d  b=%d\n", a, b);
   printf("*pa=%d  *pb=%d\n", *pa, *pb);
   printf("pa=%p  pb=%p\n", pa, pb);
   printf("----\n");

   pa++; // increment pointer pa by sizeof(int)
   pb++; // increment pointer pb by sizeof(int)
   */

   printf("a=%d  b=%d\n", a, b);
   printf("*pa=%d  *pb=%d\n", *pa, *pb);
   printf("pa=%p  pb=%p\n", pa, pb);
   printf("----\n");

   return 0;

}
