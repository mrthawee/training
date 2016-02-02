/*

This code is to find out if the underlying
architecture is little or big endian.

int x = 0x76543210;
char* c = (char*) &x;

Big Endian Format:
-----------------
Byte Address  | 0x01 | 0x02 | 0x03 | 0x04 |
              +++++++++++++++++++++++++++++
Byte Content  | 0x76 | 0x54 | 0x32 | 0x10 |

Little Endian Format:
--------------------
Byte Address  | 0x01 | 0x02 | 0x03 | 0x04 |
              +++++++++++++++++++++++++++++
Byte Content  | 0x10 | 0x32 | 0x54 | 0x76 |

*/

#include <stdio.h>

int main()
{
   unsigned int x = 0x76543210;
   char* c = (char*) &x;

   printf("x = 0x%x\n", x);
   printf("*c = 0x%x\n", *c);

   if (*c == 0x10)  /* if 1st byte holds 0x10*/
   {
      printf("Little Endian\n");
   }
   else
   {
      printf("Big Endian\n");
   }

   for (int i=0; i<4; i++)
   {
      //printf("   c[%d] = 0x%x\n", i, c[i]);
      printf("   c[%d] = 0x%x @ %p \n", i, *(c+i), (c+i));
   }
   
   return 0;
}
