#include <stdio.h>
#include <string.h>

// strcpy(char* dest, char* src);
//   caller must define 'dest' as [] - NOT pointer to TEXT segment allocation

int main()
{

   char str1[] = "string Literal";
   const char str2[] = "string Literal";
//   const char *source = "Sample string";
   char source[] = "Sample string very long long long one";

   printf("str1 = %s   str2 = %s   source = %s\n", str1, str2, source);
   printf("strlen(str1) = %d\n", (int)strlen(str1));
   printf("strlen(source) = %d\n", (int)strlen(source));

   printf("calling strcpy(str1, source)\n");
   strcpy(str1, source);  
//   strcpy(str2, source);

   printf("str1 = %s   str2 = %s\n", str1, str2);
   printf("strlen(str1) = %d\n", (int)strlen(str1));

   return 0;
}
