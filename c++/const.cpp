/*
   const_cast : to make it const or make it no-longer const

   Why use const
   1. Guards againt inadvertent write to a constant
   2. Self documenting
   3. Enables compiler to do more optimization, making code more compact
   4. const means the variable can be in read-only memory - ROM
*/
#include <iostream>
#include <stdlib.h>

using namespace std; 

int main() {
   const int i = 9;

   const int *p1 = &i; // data is const; pointer is not
   //*p1 = 5; // Not OK
   p1++;      // OK

   int* const p2 = (int*)malloc(sizeof(int)); // pointer is const, data is not
   *p2 = 20;  // OK
   // p2++;   // Not OK
   free(p2);

   const int* const p3 = &i; // both data and pointer are const;
   // p3++;   // Not OK
   //*p3 = 5;

   // if const is on the left of *, data is const
   // if const is on the right of *, pointer is const
   int const *p4 = &i;  // => const int *p4 = &i; data is const; pointer is not
   p4++;       // OK
   //*p4 = 20; // Not OK
}
