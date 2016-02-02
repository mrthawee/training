#ifndef TUTIL_H
#define TUTIL_H

#include <stdio.h>

void PrintArray(int A[], int n);

void PrintArray(int A[], int n) {
   printf("A: ");
   for (int i=0; i<n; i++) {
      printf("%d ", A[i]);
   }
   printf("\n");
}
#endif
