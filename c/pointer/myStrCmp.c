#include <stdio.h>

int myStrCmp(char *s1, char *s2)
{
   //while ((*s1!='\0') && (*s2!='\0') && (*s1 == *s2)) // work, but need to check if *s2 is '\0'
   while ((*s1!='\0') && (*s1 == *s2))
   // while (*s1 == *s2) // doesn't work with '\0' vs '\0'
   {
      s1++;
      s2++;
   }

   return (*s1 - *s2);
}

int main(void) {
   int n;
   char str1[] = "Thailand";
   char *str2  = "USA";

   n = myStrCmp(str1, str2);

   printf("myStrcmp(\"Thailand\",\"USA\") = %d\n", n);

   printf("myStrcmp(\"abc\",\"abc\") = ");
   printf("%d\n", myStrCmp("abc", "abc"));
   printf("myStrcmp(\"abc\",\"ab\") = ");
   printf("%d\n", myStrCmp("abc", "ab"));
   printf("myStrcmp(\"ab\",\"abc\") = ");
   printf("%d\n", myStrCmp("ab", "abc"));

   return 0;
}
