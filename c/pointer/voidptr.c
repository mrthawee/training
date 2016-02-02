#include <stdio.h>

int main()
{
   int a = 1025;
   int* p = &a;
   char* c = (char*)p;
   void* v = (void*)p;

   printf("&a = %p : a = %d\n", &a, a);
   printf(" p = %p : *p = %d\n", p, *p);
   // p+1 -> added by 4 bytes because its data type is int
   printf(" (p+1) = %p : *(p+1) = %d\n", (p+1), *(p+1));

   printf(" c = %p : *c = %d\n", c, *c);
   // c+1 -> added by 1 byte because its data type is char
   printf(" (c+1) = %p : *(c+1) = %d\n", (c+1), *(c+1));

   //printf(" v = %p : *v = %d\n", v, *v);
   // *v can't be printed since it doesn't have associated data type.
   // v+1 can't be done since it doesn't have associated data type.
   printf(" v = %p\n", v);
}
