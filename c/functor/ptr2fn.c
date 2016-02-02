/* Function Pointers or Pointer to function */

#include <stdio.h>

int Add(int a, int b)
{
   return a + b;
}

void PrintHello(char *name)
{
   printf("Hello %s\n", name);
}

int main()
{
   int c;

   // pointer to function that should take
   // (int, int) as arguments and return int
   int (*p)(int,int);
   // NOTE: int *p(int,int) = declare function p(int,int) which return int*
   // NOTE: int (*p)(int, int) = declare a function pointer

   // Basic in using function pointer
   p = &Add;
   c = (*p)(2,3); // it is the same as c = p(2,3);
   printf("c = %d\n", c);

   // cleaner way to use function pointer
   int (*p2)(int, int);
   p2 = Add;  // No '&' needed
   int c2 = p(4,5);  // so it can be call just like another function
   printf("c2 = %d\n", c2);

   void (*ptr)(char*);
   ptr = PrintHello;
   ptr("Tom");
   return 0;
}
