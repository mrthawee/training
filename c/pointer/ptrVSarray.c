#include <stdio.h>

void PrintArray(int A[])
{
}

int main()
{
   int A[5] = { 1, 2, 3, 4, 5 };
   int* p;
   int n;


   printf("A = %p\n", A);
   printf("*A = %d\n", *A);

   for (n=0; n<5; n++)
   {
      printf("   A+%d = %p\n", n, A+n);
      printf("   &A[%d] = %p\n", n, &A[n]);
      printf("   A[%d] = %d\n", n, A[n]);
      printf("   *(A+%d) = %d\n", n, *(A+n));
   }

   p = A; // valid
   printf("p = %p : *p=%d\n", p, *p);

   p++; // valid
   printf("p++ = %p : *(p++)=%d\n", p, *p);

   // A++ is invalid;

   for (n=0; n<5; n++)
   {
//      printf("   A[%d] = %d\n", n, A[n]);
//      printf("   &A[%d] = %p\n", n, &A[n]);
//      printf("*(p + %d) = %d\n", n, *(p+n));
   }
//   printf("sizeof(A) = %d\n", sizeof(A));
//   PrintArray(A); 
}
