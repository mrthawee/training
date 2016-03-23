#include <stdio.h>

main() {
   int arr[10];
   int i;

   for (i=-9; i<11; i++)
      printf("%d ", arr[i]);
   printf("\n");

   for (i=0; i<10; i++)
      arr[i] = i+1;

   arr[10] = 100;
   arr[-4] = -1;

   for (i=-1; i>-10; i--)
      arr[i] = i;
   
   for (i=-9; i<11; i++)
      printf("%d ", arr[i]);
   printf("\n");
}
