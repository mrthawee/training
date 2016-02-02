/*
   Need extra space!!!

   Time Complexity : O(n log n) - worst case


   - Divide and Conquer
   - Recursive
   - stable (keep things in the same order for unrelated sort info)
      => preserve the same order of keys
   - Space : Not in-place : need extra space
   - Space Complexity : O(n)
   - Time Complexity : O(n log n) - worst case

   Idea: Divide the input to 2-equal halves, sort the sub-lists, then merge

     2,4,1,6,8,5,3,7 
   
    2,4,1,6   8,5,3,7 => 1,2,4,6  3,5,7,8

   2,4  1,6   8,5  3,7 => 2,4  1,6  5,8  3,7

   2 4  1 6   8 5  3 7 // now can't break any further, merge them back (and sorting too!)

   Merge(L,R,A)  // merging 2 SORTED sub-lists(L and R) to A
   {
      nL = len(L)
      nR = len(R)
      i=j=k=0;
      // i = idx of Left sub-list
      // j = idx of Right sub-list
      // k = idx of Main list

      while (i<nL && j<nR)
      {
         if (L[i] <= R[j])
         {
            A[k] = L[i]
            i++
         }
         else
         {
            A[k] = R[j]
            j++
         }

         k++
      }

      while (i < nL)
      {
         A[k] = L[i];
         i++
         k++
      }

      while (j < nR)
      {
         A[k] = R[j]
         j++
         k++
      }
   }


   MergeSort(A)
   {
      n = len(A)

      if (n < 2)
         return;  // exit condition of this recursion
      mid = n/2
      left = arrary of size (mid)
      right = array of size (n-mid)

      for i=0 to mid-1
         L[i] = A[i]

      for i=mid to n-1
         R[i] = A[i]

      MergeSort(Left)
      MergeSort(Rigth)
      Merge(Left, Right, A)
   }
*/

#include <stdio.h>
#include <stdlib.h>
#include "tutil.h"

int A[] = { 2, 4, 1, 6, 8, 5, 3, 7 };

void Merge(int L[], int nL, int R[], int nR, int A[], int n);
void MergeSort(int A[], int n);

void Merge(int L[], int nL, int R[], int nR, int A[], int n) {
   int i=0;
   int j=0;
   int k=0;
   
   while (i<nL && j<nR) {
      if (L[i] <= R[j]) {
         A[k] = L[i];
         i++;
      } else {
         A[k] = R[j];
         j++;
      }
      k++;
   }

   while  (i < nL) {
      A[k] = L[i];
      i++;
      k++;
   }

   while (j < nR) {
      A[k] = R[j];
      j++;
      k++;
   }
}

void MergeSort(int A[], int n) {

   if (n < 2)
      return;

   int mid = n/2;

   int *L = (int*)malloc(sizeof(int)*mid);
   int *R = (int*)malloc(sizeof(int)*(n-mid));

   for (int i=0; i<mid; i++)
      L[i] = A[i];
   for (int i=mid; i<n; i++)
      R[i-mid] = A[i];

   PrintArray(L, mid);
   PrintArray(R, n-mid);

   MergeSort(L, mid);
   MergeSort(R, n-mid);

   PrintArray(L, mid);
   PrintArray(R, n-mid);

   Merge(L, mid, R, n-mid, A, n);

   PrintArray(A, n);

   free(L);
   free(R);
}

int main() {

//   int A[] = { 2, 9, 1, 7, 3, 4 };
   int A[] = { 2, 9, 1, 7, 3, 4, 5 };

   PrintArray(A,7);
   MergeSort(A, 7);
   PrintArray(A,7);

}
