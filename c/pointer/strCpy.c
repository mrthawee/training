#include <stdio.h>
#include <string.h>

// strcpy(char* dest, char* src);
//   caller must define 'dest' as [] - NOT pointer to TEXT segment allocation

int main()
{

   char str1[] = "string Literal";
   const char str2[] = "string Literal";
//   const char *source = "Sample string";
   char source[] = "Sample string";

   printf("str1 = %s   str2 = %s\n", str1, str2);

   strcpy(str1, source);  
//   strcpy(str2, source);

   printf("str1 = %s   str2 = %s\n", str1, str2);

   return 0;
}
