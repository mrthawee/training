#include <stdio.h>

// sort from low to high
void BubbleSort(int* A, int n)
{
   int tmp;
   
   for (int i=0; i<n; i++)
   {
      printf ("i=%d ", i);
      for (int j=0; j<n-1; j++)
      //for (int j=0; j<n-1-i; j++) // optimized for low to high sorting
      {
         printf ("  j=%d", j);
         if (A[j] > A[j+1])   // move the highest value to the right
         {
            tmp = A[j];
            A[j] = A[j+1];
            A[j+1] = tmp;
         }
      }
      printf("\n");
   }
}

int main()
{
   //int A[] = { 33,92,1,53,46,4};
   int A[] = { 3,2,1,5,6,4};

   BubbleSort(A, 6);
   printf("A: ");
   for (int i=0; i<6; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");
}
