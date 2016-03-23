#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(int n) {

   int r = 0;
   int tmpN = n;

   while (n != 0) {
      r = r * 10 + n%10;
      n /= 10;
   }


   return (r == tmpN);
}

int isStrPalindrome(char *str) {

   int len = strlen(str);
   int isP = 1;
   int mid = len>>1; // len / 2

   for (int i=0; i<mid; i++ ) {
      if (str[i] != str[len-1-i]) {
         printf("str[%d]=%c  !=  str[%d]=%c\n", i,str[i],len-1-i,str[len-1-i]);
         isP = 0;
         break;
      }
   }

   return isP;
}

int main(void) {

   int x = 0;

   printf("Enter a number: ");
   scanf("%d", &x);

   if (isPalindrome(x)) {
      printf("%d is palindrome.\n", x);
   } else {
      printf("%d is not palindrome.\n", x);
   }

   char str[20] = "\0";

   printf("Enter a string: ");
   scanf("%s", str);
   if (isStrPalindrome(str)) {
      printf("%s is palindrome.\n", str);
   } else {
      printf("%s is not palindrome.\n", str);
   }

   return 0;
}
