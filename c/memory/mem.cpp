/* 
C Functions:
  malloc
  calloc
  realloc
  free

C++ Operators:
  new    - type safe : return pointer to memory for a specific data type
  delete - type safe : delete memory for a specific data type
*/

// This file must be compiled with g++ since it uses C++ syntax and header file

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int total; // goes on global

int main()
{
   int a; // goes on stack
   int* p;

   p = (int*)malloc(sizeof(int)); // memory from heap - malloc return void*
   *p = 10; // dereference pointer p to 10 - set to 10;

   free(p);

   // NOTE!!! previous heap allocation is dangling if we don't call free(p) first
   p = (int*)malloc(sizeof(int)); // another heap allocation
   *p = 20; // dereference pointer p to 20 - set to 20;
   free(p);

   p = (int*)malloc(20*sizeof(int));  // array of [20] int
   // now we can use p[0], p[1], ..., p[19]
   // also *p, *(p+1), ..., *(p+19)

   free(p);

   p = new int;     // C++ style - memory allocation
   *p = 10;
   delete p;        // C++ style - memory de-allocation

   p = new int[20]; // C++ style - memory allocation
   delete[] p;      // C++ style - memory de-allocation
}
