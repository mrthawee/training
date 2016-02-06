#include <stdio.h>

int GetInt() {
   int n;

   scanf("%d", &n);

   return n;
}

int main(void)
{
   int num;
   do {
      printf("Enter a positive integer: ");
      num = GetInt();
   } while (num < 0);

   int factorial;
   for (int i=1; i<=num; i++)
      factorial *= i;

   printf("%d! = %d\n", num, factorial);

   return 0;
}
