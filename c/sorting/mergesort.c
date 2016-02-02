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

/*
#include <stdio.h>
#include "tutil.h"

int A[] = { 2, 4, 1, 6, 8, 5, 3, 7 };

void Merge(int L[], int R[], int A[]);
void MergeSort(int A[]);

void MergeSort(int A[]) {
   int n = 
}
*/
#include <iostream>
using namespace std;

int a[50];
void merge(int,int,int);
void merge_sort(int low,int high)
{
 int mid;
 if(low<high)
 {
  mid = low + (high-low)/2; //This avoids overflow when low, high are too large
  merge_sort(low,mid);
  merge_sort(mid+1,high);
  merge(low,mid,high);
 }
}
void merge(int low,int mid,int high)
{
 int h,i,j,b[50],k;
 h=low;
 i=low;
 j=mid+1;

 while((h<=mid)&&(j<=high))
 {
  if(a[h]<=a[j])
  {
   b[i]=a[h];
   h++;
  }
  else
  {
   b[i]=a[j];
   j++;
  }
  i++;
 }
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) a[k]=b[k];
}
int main()
{
 int num,i;

cout<<"********************************************************************************"<<endl;
 cout<<"                             MERGE SORT PROGRAM "<<endl;

cout<<"********************************************************************************"<<endl;
 cout<<endl<<endl;
 cout<<"Please Enter THE NUMBER OF ELEMENTS you want to sort [THEN PRESS ENTER]:"<<endl;
 cin>>num;
 cout<<endl;
 cout<<"Now, Please Enter the ( "<< num <<" ) numbers (ELEMENTS) [THEN PRESS ENTER]:"<<endl;
 for(i=1;i<=num;i++)
 {
  cin>>a[i] ;
 }
 merge_sort(1,num);
 cout<<endl;
 cout<<"So, the sorted list (using MERGE SORT) will be :"<<endl;
 cout<<endl<<endl;

 for(i=1;i<=num;i++)
 cout<<a[i]<<"  ";

 cout<<endl<<endl<<endl<<endl;
return 1;

}

