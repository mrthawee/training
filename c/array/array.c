#include <stdio.h>

// same as int SumArray(int A[], int size) {
// because when passing array to a function, C actually passes it as a pointer
// to the base address of that array only
//
// NOTE: sizeof(A) within this function will return 4, not 20, since it is the
// sizeof (int*)

int SumArray(int* A, int size) {
   int i, sum = 0;
   for (i=0; i<size; i++) {
      sum += A[i];
   }

   return sum;
}

int Sum2DArray(int A[][3], int x, int y) {
   int i, j, sum = 0;

   printf ("size of A[][] = %lu\n", sizeof(A[0])/sizeof(A[0][0]));
   for (i=0; i<x; i++) {
      for (j=0; j<y; j++) {
         sum += A[i][j];
         //sum += *((A+i*y)+j);
      }
   }

   return sum;
}

int main() {
   int A[] = {1,2,3,4,5};
   int A2D[2][3] = { {1,2,3}, {4,5,6} };

   int size = sizeof(A)/sizeof(A[0]);
   int total = SumArray(A, size);
   printf ("size of A[] = %lu\n", sizeof(A)/sizeof(A[0]));
   printf("Sum of Array = %d\n", total);

//   int x = sizeof(A2D[0])/sizeof(A2D[0][0]);

//   printf ("size of A2D[] = %lu\n", sizeof(A2D)/sizeof(A2D[0][0]));

   total = Sum2DArray(A2D, 2, 3);
   printf("Sum 2D = %d\n", total);

}
