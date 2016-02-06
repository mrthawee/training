#include <stdio.h>
#include <string.h>

int square (int big, int temp);

int main(void) {
   int sum, i;
   char string[120];

   sum = 0;
   strcpy(string, "Hello!");

   for (i=1; i<=10; i++) {
      sum += 1;
      sum = square(sum, i);
   }

   printf("sum=%d\n", sum);

   return 0;
}

int square(int big, int temp) {
   int i;

   i = big;
   if (big > 10) 
      i = i % 10;

   return (i*temp);
}
