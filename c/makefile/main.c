#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"

/*
int timesTwo(int n) {
   return n * 2;
}

int square(int n) {
   return n * n;
}

char *evenOddMsg(int n) {
   if (n % 2 == 0)
      return "Even";
   else
      return "Odd";
}
*/

//int getNextEvenInt();
//extern int lastEven;

int main(int argc, char **argv) {
   printf("5 * 2 = %d\n", timesTwo(5));
   printf("3^2 = %d\n", square(3));
   printf("42 even/odd?: %s\n", evenOddMsg(42));
   printf("Pi = %f\n", PI);

   for (int i=0; i<3; i++) {
      printf("even: %d\n", doIt());
//      printf("even: %d\n", getNextEvenInt());
//      printf("last even: %d\n", lastEven);
   }

   return EXIT_SUCCESS;
}
