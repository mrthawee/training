#include <stdio.h>

int SumOfElements(int A[], int size)
{
   int i, sum=0;
   for(i=0; i<size; i++)
   {
      sum += A[i];
   }

   return sum;
}

void Double(int* A, int size) // (int A[]) is in fact (int* A) by compiler
{
   int i;

   for (i=0; i<size; i++)
   {
      A[i] = 2 * A[i];
   }
}

int main()
{
   int A[] = {1,2,3,4,5};
   int size = sizeof(A)/sizeof(A[0]);  // # of bytes of A -> 20 / sizeof(int) 4
   int total = SumOfElements(A, size);
   int i;
   
   printf("Sum = %d\n", total);

   Double(A, size);
   for(i=0; i<size; i++)
   {
      printf("   A[%d] = %d\n", i, A[i]);
   }

   return 0;
}
