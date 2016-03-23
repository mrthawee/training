#include <stdio.h>

main() {
   int arr[2][3] = { 1,2,3,4,5,6 };

   int i;
   for (i=0; i<6; i++)
      printf("%d ", arr[0][i]); // works! but very bad idea!!!
}
