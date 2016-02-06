#include "mymath.h"  // to use 'Pi'

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

static int lastEven = 0;
// Make static to prevent outside access.
static int getNextEvenInt() {
   lastEven += 2;

   return lastEven;
}

int doIt() {
   return getNextEvenInt();
}
