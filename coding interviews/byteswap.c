#include <stdio.h>

short bswap16(short a) {
   a = ((a & 0x00FF) << 8) | ((a & 0xFF00) >> 8);
   return a;
}

int bswap32(int a) {
   a = ((a & 0x000000FF) << 24) |
       ((a & 0x0000FF00) <<  8) |
       ((a & 0x00FF0000) >>  8) |
       ((a & 0xFF000000) >> 24);
   return a;
}

long bswap64(long a) {
   a = ((a & 0x00000000000000FF) << 56) |
       ((a & 0x000000000000FF00) << 40) |
       ((a & 0x0000000000FF0000) << 24) |
       ((a & 0x00000000FF000000) <<  8) |
       ((a & 0x000000FF00000000) >>  8) |
       ((a & 0x0000FF0000000000) >> 24) |
       ((a & 0x00FF000000000000) >> 40) |
       ((a & 0xFF00000000000000) >> 56);
   return a;
}

int main(void) {
   short s = 0x1234;
   int   i = 0x12345678;
   long  l = 0x123456789abcdef0;

   s = bswap16(s);
   i = bswap32(i);
   l = bswap64(l);

   printf("s=0x%x  i=0x%x  l=0x%lx\n", s, i, l);
}
