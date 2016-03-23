#include <stdio.h>

main() {
   int i = 5;
   i = --i + i++;
   printf("i=5; --i + i++ = %d\n", i);
   i = 5;
   i = i-- + i++;
   printf("i=5; i-- + i++ = %d\n", i);

   i = 5;
   i = --i + ++i;
   printf("i=5; --i + ++i = %d\n", i);
   i = 5;
   i = i-- + ++i;
   printf("i=5; i-- + ++i = %d\n", i);

   i = 5;
   i = ++i + --i;
   printf("i=5; ++i + --i = %d\n", i);
   i = 5;
   i = i++ + --i;
   printf("i=5; i++ + --i = %d\n", i);

   i = 5;
   i = ++i + i--;
   printf("i=5; ++i + i-- = %d\n", i);
   i = 5;
   i = i++ + i--;
   printf("i=5; i++ + i-- = %d\n", i);


/*
   i = 5;
   i = i-- + ++i;
   printf("i=5; i-- + ++i = %d\n", i);

   i = 5;
   i = ++i + i--;
   printf("i=5; ++i + i-- = %d\n", i);
   i = 5;
   i = i++ + i--;
   printf("i=5; i++ + i-- = %d\n", i);
*/

}
