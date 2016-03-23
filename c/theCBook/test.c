#include <stdio.h>

main() {
   int x = 0;

   printf("%x, %x, %x\n", x, -x, ~x);

   x = 1;
   printf("%x, %x, %x\n", x, -x, ~x);

   x = ~0xF0F;  /* set x = 0x0f0 with prefix 0f 111111111 .... */
   printf("%x\n", x);
}
