#include <stdio.h>
#include <string.h>

// (1) string is a group of characters
// how to store a string in char array?  
//  size of char array must be >= num of characters + 1
//  + 1 is for '\0'

// (2) Arrays and pointers are different types that are used in similar manner

// (3) Arrays are always passed to function by reference 

void charPtrVsArray()
{
   char c1[] = "Hello";
   char* c2;
   int i;
   
   printf("c1 = %s\n", c1);
   c2 = c1; // valid
   // c1 = c2; is invalid -> compilation error

   printf("c2[1] = %c\n", c2[1]);

   c2[0] = 'A';
   printf("c1 = %s\n", c1);

   for(i=0; i<strlen(c2); i++)
   {
      printf("   c2[%d] = %c\n", i, c2[i]);
      printf("   *(c2+%d) = %c\n", i, *(c2+i));
   }  
}

int test()
{
   char str[] = "john"; // '\0' is auto added

   int str_len = sizeof(str);

   int i;

   printf("str = %s\n", str);
   int len = strlen(str);
   int size = sizeof(str);
   printf("   len of C = %d\n", len);
   printf("   sizeof C = %d\n", size);

   for (i=0; i<str_len; i++)
   {
//      printf( "c[%d] = %c\n", i, str[%i]);
   }

   return 0;
}

// arg is c[] which is treated as pointer to the 1st char of string
//  c++ is move one char at a time
void myPrintStr(char* c)
{
   printf("%s\n", c);

   int i=0;
   while (*(c+i) != '\0')
   {
      printf("%c", c[i]);
      i++;
   }
   printf("\n");

   while(*c != '\0')
   {
      printf("%c", *c);
      c++;
   }
   printf("\n");
}

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

int main()
{
   char C[20];
   C[0] = 'J';
   C[1] = 'O';
   C[2] = 'H';
   C[3] = 'N';
   C[4] = '!';
//   C[5] = '\0';

   int len = strlen(C);
   int size = sizeof(C);
   printf("C = %s\n", C);
   printf("   len of C = %d\n", len);
   printf("   sizeof C = %d\n", size);

   test();
   charPtrVsArray();

   printf("Test myPrintStr()\n");
   myPrintStr("abcdefg");

   printf("%d\n", myStrCmp("", ""));
   printf("%d\n", myStrCmp("AB", "ABC"));
   printf("%d\n", myStrCmp("ABC", "AB"));
   printf("%d\n", myStrCmp("ABC", "ABC"));
}
