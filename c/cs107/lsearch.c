#include <stdio.h>
#include <string.h>

void *lsearch(void *key, void *base, int n, int elemSize,
               int (*cmpFn)(void *, void *)) {
   int i=0;
   for (i=0; i<n; i++) {
      void *elemAddr = (char*)base + (i * elemSize);
      if (cmpFn(key, elemAddr) == 0) {
         return elemAddr;
      }
   }

   return NULL;
}

int IntCmp(void *elem1, void *elem2) {
   int *ip1 = elem1;
   int *ip2 = elem2;

   return *ip1 - *ip2;
}

int StrCmp(void *elem1, void *elem2) {
   char *s1 = *(char**)elem1;
   char *s2 = *(char**)elem2;

   return strcmp(s1, s2);
}

main() {
   /* Generic search with integer */
   int arr[] = { 1, 2, 3, 4, 5, 6 };
   int size = 6;
   int num = 5;
   int *found = lsearch(&num, arr, 6, sizeof(int), IntCmp);
   if (found == NULL)
      printf("Not found!\n");
   else 
      printf("found @ %p = %d\n", found, *found);

   /* Generic search with array to string */
   char *notes[] = { "Ab", "F#", "B", "Gb", "D" };
   char *favoriteNote = "Gb";
   char **found2 = lsearch(&favoriteNote, notes, 5, sizeof(char *), StrCmp);
   if (*found2 == NULL)
      printf("Not found!\n");
   else 
      printf("found @ %p = %s\n", *found2, *found2);
}
