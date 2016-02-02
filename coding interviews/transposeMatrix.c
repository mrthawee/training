#include <stdio.h>

//void printMatrix(int m[][4], int r, int c) {
void printMatrix(int *m, int r, int c) {
   for (int i=0; i<r; i++) {
      for (int j=0; j<c; j++) {
         printf("%d ", *((m+i*c)+j));
      }
      printf("\n");
   }
}

//void transposeMatrix(int m[][4], int r, int c, int n[][2]) {
void transposeMatrix(int *m, int r, int c, int *n) {
   for (int i=0; i<r; i++)  {
      for (int j=0; j<c; j++) {
         *((n+j*r)+i) = *((m+i*c)+j); // n[j][i] = m[i][j]
      }
   }
}


int main(int argc, char* argv[]) {

   int m[2][4] = { { 1, 42, 93, 54 },
                   { 15, 26, 37, 8 } };

   int n[4][2];


   int *pm = (int*)&m;
   printf("Original Matrix:\n");
   printMatrix(pm, 2, 4);
   printf("\n");

   int *pn = (int*)&n;
   transposeMatrix(pm, 2, 4, pn);

   printf("Transpose Matrix:\n");
   printMatrix(pn, 4, 2);
   printf("\n");

   int m2[3][5] = { { 5, 4, 3, 2, 1 },
                    { 2, 4, 6, 8, 10 },
                    { 9, 7, 5, 3, 1 } };

   int n2[5][3];

   pm = (int*)&m2;
   printf("Original Matrix:\n");
   printMatrix(pm, 3, 5);
   printf("\n");

   pn = (int*)&n2;
   transposeMatrix(pm, 3, 5, pn);

   printf("Transpose Matrix:\n");
   printMatrix(pn, 5, 3);
   printf("\n");

   return 0;
}
