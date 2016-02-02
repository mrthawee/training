/* Pointers as functions returns */

#include <stdio.h>
#include <stdlib.h>

// call by value
int Add1(int a, int b) 
{
   printf("In Add1 (call by value) :\n");
   printf("    addr of a = %p\n", &a);
   printf("    value of a = %d\n", a);

   int c = a + b;
   return c;
}

// call by reference
int Add2(int* a, int* b)
{
   printf("In Add2 (call by reference) :\n");
   printf("    addr of a = %p\n", &a);
   printf("    value of a = %p\n", a);
   printf("    value at addr stored in a = %d\n", *a); 

   int c = (*a) + (*b);
   return c;
}

int* Add3(int* a, int *b)
{
   int c = *a + *b;

   return &c; // BAD!!! returning address of local variable (stack addr!)
   // Good practise is to allocate memory on HEAP and return that address
}

int* Add4(int* a, int *b)
{
   int* c = (int*)malloc(sizeof(int));
   *c = *a + *b;

   printf("In Add4: \n");
   printf("    addr of c = %p\n", c);

   // Good practise is to allocate memory on HEAP and return that address
   return c;
}

int main()
{
   int x = 2, y = 4;

   printf("In main():\n");
   printf("    addr of x = %p\n", &x);
   printf("    addr of y = %p\n", &y);

   int z = Add1(x , y);
   printf("Add1 -> sum = %d\n", z);

   int s = Add2(&x , &y);
   printf("Add2 -> sum = %d\n", s);

   int* s3 = Add3(&x, &y);
   printf("Add3 -> sum = %d\n", *s3);

   int* s4 = Add4(&x, &y);
   printf("Add4 -> sum = %d\n", *s4);
   printf("    addr of s4= %p\n", s4);
   
   free(s4); // memory should be freed!
}
