#include <iostream>
#include <stdlib.h>

using namespace std;

long mystrtol(const char* s, char** end, int base = 10) {
   return strtol(s, end, base);
}

int main() {
   long x;
   char s1[] = "1000";
   char *p;

   x = mystrtol(s1, &p, 36);
   cout << "Base 36 = " << x << endl;

   x = mystrtol(s1, &p, 16);
   cout << "Base 16 = " << x << endl;

   x = mystrtol(s1, &p, 10);
   cout << "Base 10 = " << x << endl;

   x = mystrtol(s1, &p, 2);
   cout << "Base 2 = " << x << endl;

   x = mystrtol(s1, &p);
   cout << "Base 10 using default argument = " << x << endl;
}
