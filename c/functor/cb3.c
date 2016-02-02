#include <stdio.h>
#include <stdlib.h>

// callback function should compare 2 integers
//   return 1 if 1st element is greater
//   return 0 if both are equal
//   return -1 if 1st element is less

int compare(int a, int b)
{
   //return (a > b) ? 1 : -1;
   return (a - b);
   //return (b - a); // for sorting of high to low
}

// for sorting of the absolute value
// Ex  -2, 3,-5, 1 => 1, -2, 3, -5
int abs_cmp(int a, int b)
{
   //return (abs(a) > abs(b)) ? 1 : -1;
   return (abs(a) - abs(b));
}

void BubbleSort(int *A, int n, int (*compare)(int,int))
{
   int tmp,i,j;
   for (i=0; i<n; i++)
      for (j=0; j<n-1; j++)
         if (compare(A[j],A[j+1]) > 0 ) // yes for low to high
         {
            tmp = A[j];
            A[j] = A[j+1];
            A[j+1] = tmp;
         }
}

int main()
{
   int i, A[] = {3,2,1,5,6,4};
   BubbleSort(A, 6, compare);
   printf("A: ");
   for (i=0; i<6; i++)
      printf("%d ", A[i]);
   printf("\n");

   int B[] = { -3, 1, -5, 2, 9};
   BubbleSort(B, 5, abs_cmp);
   printf("B: ");
   for (i=0; i<5; i++)
      printf("%d ", B[i]);
   printf("\n");
}
