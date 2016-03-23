#include <stdio.h>
#include <string.h>

void swap(void *x, void *y, int len) {
   char buf[len];
   memcpy(buf, x, len);
   memcpy(x, y, len);
   memcpy(y, buf, len);
}

main() {
   int a = 5, b = 10;

   printf("a=%d  b=%d\n", a, b);
   swap(&a, &b, sizeof(int));
   printf("a=%d  b=%d\n", a, b);

   float f = 3.5, e = 9.23431;
   printf("f=%f  e=%f\n", f, e);
   swap(&f, &e, sizeof(float));
   printf("f=%f  e=%f\n", f, e);

   char *h = "Fred";
   char *w = "Wilma";

   printf("h=%s  w=%s\n", h, w);
   swap(&h, &w, sizeof(char *)); 
   printf("h=%s  w=%s\n", h, w);
}
