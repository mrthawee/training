#include <stdio.h>

int main()
{
   int a;
   int *p;

   p = &a;  // &a = address of a

   printf("a = %d\n", a);
   printf("Only p = &a \n");  // &a = address of a
   printf("p is uninitialized. Let's see what its value is.\n");
   printf("p = %p\n", p);
   printf("p+1= %p\n", (p+1)); // It should be incremented by 4 since it is pointer to in
   printf("size of *p = %lu\n", sizeof(*p));
   printf("size of int = %lu\n", sizeof(int));
   printf("*p = %d\n", *p);
   printf("NOTE: size of p = %lu\n", sizeof(p));

   printf("now set a = 10\n");
   a = 10;
   printf("p = %p\n", p);
   printf("*p = %d\n", *p);
   printf("&a = %p\n", &a);

   *p = 12;  // dereferencing p to value of 12
   printf("dereferencing *p = 12  Let's see what a is now.\n");
   printf("a = %d\n", a);
}
