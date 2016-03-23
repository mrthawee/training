#include <stdio.h>

main() {
   int a = 0;
   int b = 1;
   int c = 0;

   if (a&b == c) {
      printf("Yeah!\n");
   } else {
      // a = 1, b = 1, c = 0 and it comes here.  
      // So, it checks if a == 0 first, then come here without b == c
      printf("Nope!\n");
   }

}
