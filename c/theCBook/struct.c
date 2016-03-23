#include <stdio.h>
#include <stdlib.h>

struct test{
   char  c;
   short s1;
   short s2;
};

struct test2{
   char  c;
   int   i;
   short s;
};

struct test3{
   char  c;
   int   i[2];
   short s;
};

struct test4{
   char  c;
   long  l;
   short s;
};

struct test5{
   char  c;
   short s;
   long  l;
};

main() {
   printf("%d\n", (int)sizeof(struct test));
   printf("%d\n", (int)sizeof(struct test2));
   printf("%d\n", (int)sizeof(struct test3));
   printf("%d\n", (int)sizeof(struct test4));
   printf("%d\n", (int)sizeof(struct test5));
}
