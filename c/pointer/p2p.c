#include <stdio.h>

int main()
{
   int x = 5;
   int* p;
   int** q;
   int*** r;

   p = &x;
   q = &p;
   r = &q;

   printf("x=%d\n", x);
   printf("p = &x\n");
   printf("q = &p\n");
   printf("r = &q\n");
   printf("p=%p : *p=%d\n", p, *p);
   printf("q=%p : *q=%p : **q=%d\n", q, *q, **q);
   printf("r=%p : *r=%p : **r=%p : ***r=%d\n", r, *r, **r, ***r);

   return 0;
}
