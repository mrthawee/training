#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
   int x = *((int*)a);  // typecast void* to int* then dereference to get value
   int y = *((int*)b);  // typecast void* to int* then dereference to get value

   return x - y;
}

int main() 
{
   int i, A[] = {-31, 22, -1, 50, -6, 4};

   printf("A: ");
   for (i=0; i<6; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");

   qsort(A, 6, sizeof(int), compare);

   printf("A: ");
   for (i=0; i<6; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");
}
