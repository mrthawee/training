#include <stdio.h>

struct x;

struct x *p, func(void);

void f1(void) {
   struct x { int i; };
}

struct x {
   float f;
} s_x;

void f2(void) {
   p = &s_x;
   *p = func();
   s_x = func();
}

struct x func(void) {
   struct x tmp;
   tmp.f = 0;
   return (tmp);
}

main() {

}
