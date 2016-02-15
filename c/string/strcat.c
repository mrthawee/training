#include <stdio.h>
#include <string.h>

int main(void) {
   char str[] = "Hello!";
   strcat(str, "So happy to see you!"); // Bad! : str[] has only 7 chars including '\0'

   printf("str = %s\n", str);

   return 0;
}
