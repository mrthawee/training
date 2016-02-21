#include <stdio.h>

#define HI_U12(a, b)  ((a) << 4) | ((b) >>4)
#define LO_U12(b, c)  (((b) <<8) & 0xF00) | (c)

typedef struct dataX {
   unsigned short data : 12;
} dataX_Type;

typedef union unionX {
   char data[2];
   unsigned short data1; // : 12;
//   unsigned short data2 : 12;
} unionX_Type;

struct d2 {
   short d1; //: 12;
   short d2; //: 12;
};

union u2 {
   char        c[3];
   struct d2   d;
};

/*
 * 12-bit field
 *
 * Issue: wanna read 12-bit field effectively.  How?
 *
 * What to be considerred?
 * 1. short is 16-bit data type, wasting 4-bit space
 * 2. using struct bit pack, cool! but what else to be considerred
 *    a) size of struct with bit pack is growing in double 1, 2, 4, 8, 16
 */

int main() {
   dataX_Type d1;

   int i;
   for (i=4090; i<4100; i++) {
      d1.data = i;
      printf("%d %d\n", i, d1.data);
   }

/*
   unionX_Type u;
   for (i=0; i<2; i++) {
      u.data[i] = 0xF0;
   }
   printf("%x\n", u.data1);
*/
   
/*
   for (i=0; i<3; i++) {
      ux2.data[i] = 0xFF;
   }
*/
   printf("size of struct d2 = %d\n", (int)sizeof(struct d2));
   printf("size of union u2 = %d\n", (int)sizeof(union u2));
   union u2 u;
   u.c[0] = 0x12;
   u.c[1] = 0x34;
   u.c[2] = 0x56;
//   u.c[3] = 0x78;
   printf("%x %x %x %x\n", u.c[0], u.c[1], u.c[2], u.c[3]);

   char c[3] = {0x12, 0x34, 0x56};
   struct d2 d;
   d.d1 = c[0] << 4 | c[1] >> 4;
   d.d2 = (c[1] << 8)&0xF00 | c[2];
   printf("%03x %03x\n", d.d1, d.d2);
   printf("%02x %02x\n", c[1]>>4, (c[1]<<4)&0xF0);

   unsigned dx = HI_U12(c[0], c[1]);
   unsigned dy = LO_U12(c[1], c[2]);
   printf("%03x %03x\n", dx, dy);

/*
   char  c[3] = {0x12, 0x34, 0x56};
   printf("%x %x %x\n", c[0], c[1], c[2]);
   struct d2 *p = (void*)&c[0];
//   p = (struct d2 *)&c[0];
   printf("p->data1 = %x04x\n", p->data1);
*/

}
