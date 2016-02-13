#include <stdio.h>

#define BUF_SIZE 6

int buf[6];
int rPos = 0;
int wPos = 0;

void enQ(int d) {
   printf("enQ: %d - wPos=%d rPos=%d\n", d, wPos, rPos);
   buf[wPos] = d;

   // if FULL, overwrite.
   if (rPos == (wPos + 1) % BUF_SIZE) {
      printf("Q full.\n");
      rPos = (rPos + 1) % BUF_SIZE;
   }

   wPos = (wPos + 1) % BUF_SIZE;
}

int deQ(void) {
   printf("deQ: wPos=%d rPos=%d ", wPos, rPos);
   int d = buf[rPos];
   rPos = (rPos + 1) % BUF_SIZE;
   printf("d=%d\n", d);
   return d;
}

void ptrQ(void) {
   int i,n;

   printf("rPos = %d  wPos = %d : ", rPos, wPos);
   n = rPos;
   for (i=0; i<BUF_SIZE; i++) {
      printf("%d ", buf[n]);
      n = (n+1) % BUF_SIZE;
   }
   printf("\n");

   printf("Buf: ");
   for (i=0; i<BUF_SIZE; i++) {
      printf("%d ", buf[i]);
   }
   printf("\n");
}

int main(void) {
   int i,n;

   int data[100];

   for (i=0; i<100; i++) {
      data[i] = i+1;
   }

   for (i=0; i<46; i++) {
      enQ(data[i]);
   }
   ptrQ();
}
