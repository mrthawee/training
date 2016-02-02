/* Function pointers and Callbacks */
// Function pointers can be used function arguments, so the functions can be called back


#include <stdio.h>

void A()
{
   printf("Hello\n");
}

void Test()
{
   printf("This is function Test()\n");
}


void B(void (*ptr)())  // function pointer as argument
{
   ptr();  // callback function that 'ptr' points to
}

int main()
{
   void (*p)() = A; // or void p = A;
   B(p); // just like B(A)

   p = Test;
   B(p);
}
