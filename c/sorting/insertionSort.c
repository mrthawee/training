/* 
   Time Complexity : O(n^2) with less number of comparison comparing to bubble
                     and selection sorts
   Space Complexity : Inplace

   Better than selection sort and bubble sort, but still not that good.

   1. Divide list to 2 parts: unsorted part and sorted part
   2. Pick one up from the unsorted
   3. Insert to the right position in sorted part

   Ex: list = 7, 2, 4, 1, 5, 3

   7 | 2, 4, 1, 5, 3
   2, 7 | 4, 1, 5, 3 // empty spot of "2" then shift "7" to the right first
   2, 4, 7 | 1, 5, 3
   .
   .
   1, 2, 3, 4, 5, 7 

   InsertionSort(A, n) :
   {
      for i = 1 to n-1
      {
         value = A[i]
         hole = i

         while (hole>0 && A[hole-1] > value])
         {
            A[hole] = A[hole-1];
            hole = hole -1;
         }
   
         A[hole] = value;
      }
   }

*/

#include <stdio.h>
#include "tutil.h"

int input[] = { 7, 2, 4, 1, 5, 3 };
//int input[] = { 7, 2, 4 };

void InsertionSort(int A[], int n);

void Swap(int *p, int *q) {
   int tmp = *p;
   *p = *q;
   *q = tmp;
}

int main() {
   PrintArray(input, 6);
   InsertionSort(input, 6);
   PrintArray(input, 6);
}

/*
void InsertionSort(int A[], int n) {
   for (int i=0; i<n-1; i++) {
      for (int j=i+1; j<n; j++) {
         if (A[j] < A[i])
            Swap(&A[i], &A[j]);      
      }
   }
}
*/

void InsertionSort(int A[], int n) {
   for (int i=0; i<n-1; i++) {
      int value = A[i];
      int holeIndex = i;

      while ((holeIndex >0) && (A[holeIndex-1] > value)){
         A[holeIndex] = A[holeIndex - 1];
         holeIndex--;
      }

      A[holeIndex] = value;
   }
}
