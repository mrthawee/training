/*
   Time Complexity: O(n^2)
   Space Complexity: Inplace

   BubbleSort(A, n): // Bubble to highest value to the right most
   for (i=0; i<len-2; i++)
      for (j=0; j<len-2-i; j++)
         Comparing A[j] with A[j+1]
            if A[j+1] < A[j]
               Swap A[j] with A[j+1]

   Optimization: if any pass can't find any swapping needed, the list is sorted!
*/

#include <stdio.h>
#include "tutil.h"

void BubbleSort(int A[], int n);
//void PrintArray(int A[], int n);

int input[] = { 3, 5, 2, 1, 6, 9 };
//int input[] = { 1, 2, 3, 4, 6, 9 };

int main() {
   PrintArray(input, 6);
   BubbleSort(input, 6);
}

void BubbleSort(int A[], int n) {
   for (int i=0; i<n-2; i++) {
      printf("i=%d to %d\n", 0, n-2-i);
      int foundSwapping = 0;
      for (int j=0; j<n-2-i; j++) {
         printf("Comparing A[%d]=%d vs A[%d]=%d\n", j,A[j], j+1,A[j+1]);
         if (A[j] > A[j+1]) {
            foundSwapping = 1;
            printf(" swaping A[%d] with A[%d]\n", j, j+1);
            int tmp = A[j];
            A[j] = A[j+1];
            A[j+1] = tmp;
      
         }
      }

      PrintArray(A, n);

      // Optimization:
      if (foundSwapping == 0) {
         printf("List is now sorted!\n");
         break;
      }
   }
}

/*
void PrintArray(int A[], int n) {
   printf("A: ");
   for (int i=0; i<n-1; i++) {
      printf(" %d", A[i]);
   }
   printf("\n");
}
*/
