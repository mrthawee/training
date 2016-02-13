#include <stdio.h>
#include <string.h>

int main(void) {
   char str[1000] = "\0";
   char str2[20];
   int i=0;
   for (i=0; i<10; i++) {
      sprintf(str2,"%d,", i);
      strcat(str, str2);
   }
   printf("%s\n", str);
}
