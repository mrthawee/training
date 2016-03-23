#include <stdio.h>

int main(void) {
   int a = 3;
   int *pa;

//   printf("&a=%p a=%d pa=%p *pa=%d\n", &a, a, pa, *pa);

   pa = &a;
   printf("&a=%p a=%d pa=%p *pa=%d\n", &a, a, pa, *pa);

   printf("execute: *pa++ = 5;\n"); 
   *pa++ = 5; // same as *(pa++) = 5;
//   *pa = 5;
//   pa++;

   printf("&a=%p a=%d pa=%p *pa=%d\n", &a, a, pa, *pa);

   return 0;
}
