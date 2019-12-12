#include <stdio.h>

void PointerTest() {
  int a = 1;
  int b = 2;
  int c = 3;
  int *p;
  int *q;

  printf("a=%d b=%d c=%d\n", a, b, c);

  p = &a;
  printf("p = %d\n", *p);

  q = &b;
  printf("q = %d\n", *q);

  c = *p;
  printf("c = %d\n", c);

  p = q;
  printf("p = %d\n", *p);

  *p = 13;
  printf("p = %d, q = %d\n", *p, *q);



}

int main() {
  PointerTest();

  return 0;
}
