#include <stdio.h>
#include <string.h>

//void print(const char* c) // to NOT modify this string within this function
void print(char* c)
{
   //c[0] = "y";  // can't run with 'const' in the argument
   while (*c != '\0')
   {
      printf("%c", *c);
      c++;
   }
   printf("\n");
}

int main()
{
   // char* C = "hello";  // -> string "hello" kept in TEXT/STATIC segment.
   char C[20] = "hello";  // -> string "hello" kept in STACK segment
   C[0] = 'A';            // This line works ONLY IF "hello" is in STACK segment
   print(C);
}
