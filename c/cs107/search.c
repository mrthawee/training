#include <stdio.h>
#include <string.h>

int intSearch(int key, int arr[], int size) {
   int i=0;
   for (i=0; i<size; i++) {
      if (arr[i] == key) {
         // return i;
         return key;
      }
   }
   return -1;  // not found
}

void *genSearch(void *key, void *base, int n, int elemSize) {
   int i;
   for (i=0; i<n; i++) {
      //void *elemAddr = base + (i*elemSize);
      void *elemAddr = (char*)base + (i * elemSize);
      if (memcmp(key, elemAddr, elemSize) == 0) { // byte-by-byte compare
         return elemAddr;
      }
   }

   return NULL;
}

main() {

   int a[5] = {1,2,3,4,5};
   int b = 4;

   int r = intSearch(b, a, 5);
   printf("r = %d\n", r);


   void *v = genSearch(&b, &a, 5, sizeof(int));
   //printf("v = %p, %d\n", v, (int*)v);
   printf("v = %p\n", v);
   printf("*v = %d\n", *(int*)v);
}
