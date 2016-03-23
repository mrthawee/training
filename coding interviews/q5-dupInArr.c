/*
 * An array contains N numbers ranging from 0 to N-2.  There is exactly one
 * number duplicated in the array.  How do you find the duplicated number?
 * For example, if an array with length 5 contains numbers { 0, 2, 1, 3, 2 },
 * the duplicated number is 2.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 * sum of 0 ... n = n * (n + 1) / 2
 *
 * With N numbers starting from 0, if there is no duplicated number, its sum
 * is (n-1) * n / 2
 *
 * Hence, dup number is "sum of all numbers in this array - (n-2)*(n-1)/2"
 */

int findDup(int arr[], int len) {

   int n, sum1 = 0;
   for (n=0; n<len; n++) {
      if (arr[n] < 0 || arr[n] > len - 2) {
         printf("Error: invalid number %d\n", arr[n]);
         return -1;
      }
      sum1 += arr[n];
   }

   int sum2 = ((len-1) * (len-2))/ 2;

   return sum1 - sum2;
}

int main(void) {
   int arr[] = { 0, 2, 1, 3, 4, 5, 3 };

   printf("sizeof(arr) = %ld , sizeof(int) = %ld\n", sizeof(arr), sizeof(int));
   int dup = findDup(arr, sizeof(arr)/sizeof(int));

   printf("Duplicated number is %d\n", dup);

   return 0;
}
