#include <stdio.h>

int main(void) {
   int a = 1, b = 3, c = 5;
   int *pa;
   int *pb;
   int *pc;

   pa = &a;
   pb = &b;
   pc = &c;

   printf("a=%d  b=%d c=%d\n", a, b, c);
   printf("&a=%p  &b=%p &c=%p\n", &a, &b, &c);
   printf("*pa=%d  *pb=%d *pc=%d\n", *pa, *pb, *pc);
   printf("pa=%p  pb=%p pc=%p\n", pa, pb, pc);
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

   printf("a=%d  b=%d c=%d\n", a, b, c);
   printf("&a=%p  &b=%p &c=%p\n", &a, &b, &c);
   printf("*pa=%d  *pb=%d *pc=%d\n", *pa, *pb, *pc);
   printf("pa=%p  pb=%p pc=%p\n", pa, pb, pc);
   printf("----\n");

   return 0;

}
