#include <stdio.h>
#include <stdlib.h>

main() {
   int input_c;

   while ( (input_c = getchar()) != EOF ) {
      printf("%c was read\n", input_c);
   }

   exit (EXIT_SUCCESS);
}
