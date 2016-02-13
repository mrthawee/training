#include <stdio.h>
#include <string.h>

int main(void) {
   char tmp[100];
   char str[1000];

   int i=0;
   for (i=0; i<10; i++) {
      sprintf(tmp,"%d ", i);
      strcat(str, tmp);
      printf("str %d = %s\n", i, str);
   }
}
