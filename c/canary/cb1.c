#include <stdio.h>

#define BUF_SIZE 11

int buf[BUF_SIZE];
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

void ptrQ(int startIndex) {
   int i,n;

//   printf("rPos = %d  wPos = %d : ", rPos, wPos);
   n = (rPos-startIndex + BUF_SIZE)%BUF_SIZE;
   printf("rPos=%d  wPos=%d  n=%d :\n\t", rPos, wPos,n);
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

int readQ(int nPosB4Last) {
  int i = (wPos-nPosB4Last + BUF_SIZE) % BUF_SIZE;
  printf("wPos=%d  i=%d : data=%d\n", wPos, i, buf[i]);

  return buf[i];
}


int main(void) {
   int i,n;

   int data[100];

   for (i=0; i<100; i++) {
      data[i] = i+1;
   }

   for (i=0; i<45; i++) {
      enQ(data[i]);
   }
   ptrQ(0);

   for (i=10; i>0; i--) {
      int r = readQ(i);
   }
}
