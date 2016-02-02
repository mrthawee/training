#include <iostream>

using namespace std;

//void print2DArray(int array[][], int nRow, int nCol); --> can't compile
void print2DArray(int array[][3], int nRow, int nCol);

int main() {
   int a[2][3] = { { 2, 4, 6 },
                   { 1, 3, 5 } };

   print2DArray(a, 2, 3);
}

//void print2DArray(int array[][], int nRow, int nCol) { --> won't compile
void print2DArray(int array[][3], int nRow, int nCol) {
   for (int r=0; r<nRow; r++) {
      for (int c=0; c<nCol; c++) {
         cout << array[r][c] << " ";
      }
      cout << endl;
   }
}
