#include <stdio.h>
#include <stdlib.h>

/* Case 1: union with basic datat type -> the biggest one wins! */
union Data {
   int   i;
   float f;
   char  c;
   long  l;
}; // size of union Data = sizeof(long) = 8 bytes


/* Case 2: union with struct in size -> the biggest one wins! */
struct S {
   char  c1;
   char  c2;
};

union U {
   char c;     // 1 byte
   struct S s; // 2 bytes
}; // size of union U = sizeof(struct S) = 2 bytes


/* Case 3: bit pack fields 
 *   - just check of size after packing 
 *   - biggest field wins as usual
 */

struct S2 {
   char  c1:2;
   char  c2:6;
};

union U2 {
   char c;     // 1 byte
   struct S2 s; // 1 bytes
}; // size of union U = 1 byte


struct S3 {
   short sh1;  // 2 bytes
   char  c;    // 1 byte
}; // sizeof S3 is 4 bytes! not 3bytes!

union U3 {
   char c;  
   struct S3 s;
};

struct Sx{
   char c;  // 1 byte
   int  i;  // 4 byte
}; // not 5 bytes, but 8!!!

struct X{
   short c1:12;
   short c2:12;
/*
   short c3:12;
   short c4:12;
   short c5:12;
   short c6:12;
   short c7:12;
   short c8:12;
*/
};

int main() {
   printf("size of union Data = %d\n", (int)sizeof(union Data));

   printf("size of struct S = %d\n", (int)sizeof(struct S));
   printf("size of union U = %d\n", (int)sizeof(union U));

   printf("size of struct S2 = %d\n", (int)sizeof(struct S2));
   printf("size of union U2 = %d\n", (int)sizeof(union U2));

   printf("size of struct S3 = %d\n", (int)sizeof(struct S3));
   printf("size of union U3 = %d\n", (int)sizeof(union U3));

   printf("size of struct Sx = %d\n", (int)sizeof(struct Sx));
   printf("size of char[5] = %d\n", (int)sizeof(char[5]));
   printf("size of char[6] = %d\n", (int)sizeof(char[6]));
   printf("size of char[7] = %d\n", (int)sizeof(char[7]));

   printf("size of struct X = %d\n", (int)sizeof(struct X));
}
