#include <stdio.h>

int main(int argc, char* argv[]) {
   int d[] = { 0, 2, 3, 2, 3 };
   int foundDup = 0;

   int len = sizeof(d)/sizeof(int);

   for (int i=0; i<len; i++) {
      for (int j=i+1; j<len; j++) {
         if (d[i] == d[j]) {
            printf("found d[%d] = d[%d] = %d\n", i, j, d[i]);
            foundDup = 1;
         }
      }
   }

   if (foundDup == 0) {
      printf("No dup found.\n");
   }

   return 0;
}
