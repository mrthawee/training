#include <stdio.h>

int main() {
   int a = 1, b =3, c = 5;

   int *p1 = &b;
   int *p2 = &b;

   printf("a = %d &a = %p\n", a, &a);
   printf("b = %d &b = %p\n", b, &b);
   printf("c = %d &c = %p\n", c, &c);
   printf("\n");

   printf("*p1 = %d  *p1 = %p\n", *p1, p1);
   printf("*p2 = %d  *p2 = %p\n", *p2, p2);

   printf("execute: *(p1++); // same as *p1++;\n");
   printf("execute: (*p2)++;\n");
   *(p1++);  // inc pointer p @ sizeof(int) first, then dereference for the value
   (*p2)++;  // inc value p first, then increment the pointer 

   printf("*p1 = %d  *p1 = %p\n", *p1, p1);
   printf("*p2 = %d  *p2 = %p\n", *p2, p2);

   printf("a = %d &a = %p\n", a, &a);
   printf("b = %d &b = %p\n", b, &b);
   printf("c = %d &c = %p\n", c, &c);
}
