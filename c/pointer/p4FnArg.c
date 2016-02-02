#include <stdio.h>

void Increment(int* a)
{
   printf("  *a = %d\n", *a);
   *a = (*a) + 1;
   printf("  *a = %d\n", *a);
}

int main()
{
   int a = 10;

   printf("a=%d\n", a);
   Increment(&a);
   printf("a=%d\n", a);
}
