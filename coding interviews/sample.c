/*
Little-endian output:
x in hex: 112a380
x by bytes: 80 a3 12 1
After htonl()
x in hex: 80a31201
x by bytes: 1 12 a3 80

Big-endian output:
x in hex: 112a380
x by bytes: 1 12 a3 80
After htonl()
x in hex: 112a380
x by bytes: 1 12 a3 80
*/
#include <stdio.h>
#include <arpa/inet.h>

int main(void) {
   int i;
   //long x = 0x112A380deadbeef;
   int x = 0x112A380;
   unsigned char *ptr = (unsigned char*) &x; // byte pointer

   // observe value in host byte order
   printf("x in hex: 0x%x\n", x);
   printf("x by bytes: ");
   
   for (i=0; i<sizeof(int); i++)
      printf("%x\t", ptr[i]);
   printf("\n");

   // observe value in network byte order
   x = htonl(x);
   printf("After hotnl()\n");
   printf("x in hex: %x\n", x);
   printf("x by bytes: ");

   for (i=0; i<sizeof(int); i++)
      printf("%x\t", ptr[i]);
   printf("\n");

   return 0;
}
