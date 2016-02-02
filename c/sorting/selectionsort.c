/*
   Time Complexity : O(n^2)
   Space Complexity : inplace

   SelectionSort(A, n) // move the min to the left most
   {
      for i 0 to n - 2
      {
         // find the min 
         // swap min to i 

         iMin = i
         for j=i+1 to n -1
         {
            if (A[j] < A[iMin])
               swap(A[j], A[iMin)
         } 
      }
   }

*/
#include <stdio.h>

void selectionSort(int A[], int len);
void printArray(int A[], int n);

int input[] = { 2, 5, 4, 3, 7, 1  };

int main () {

   printArray(input, 6);

   selectionSort(input, 6);

}

void selectionSort(int A[], int len) {
   for (int i=0; i<len-1; i++) { 
      printf("i=%d\n", i);

      int iMin = i;
      for (int j=iMin+1; j<len; j++) {
         printf("comparing: A[%d]=%d vs A[%d]=%d\n", i,A[i],j,A[j]);
         if (A[j] < A[iMin]) {
            iMin = j;
         }
      }
   
      if (iMin != i) {
         printf("  swapping: A[%d] and A[%d]\n", i, iMin);
         int tmp = A[i];
         A[i] = A[iMin];;
         A[iMin] = tmp;
      } else {
         printf("  no swapping needed\n");
      }
      printArray(A, len);
   }
}
void printArray(int A[], int n) {
   printf("A:");
   for (int i=0; i<n; i++) {
      printf(" %d", A[i]);
   }
   printf("\n");
}

