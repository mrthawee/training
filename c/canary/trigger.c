#include <stdio.h>

#define READY     0
#define FOUND     1

#define TRIGGER_VALUE 40000

/*
 * logData(data[], startIndex, endIndex)
 */
void logData(unsigned short* data, int i) { 
   int n=0;
   
   for (n=i-4; n<=i+5; n++) {
      printf("Found sample %d: ", i);
      for (n=i-4; n<=i+5; n++) {
         printf("%hu,", data[n]);
      }
      printf("\n");
   }
}

void detectLoudNoise(unsigned short* data) {
   int i=0;
   int n=0;
   int state = READY;

   for (i=0; i<1000; i++) {
      if ((data[i] >= TRIGGER_VALUE) && (state == READY)){
         /*
         printf("Found sample %d: ", i);
         for (n=i-4; n<=i+5; n++) {
            printf("%hu,", data[n]);
         }
         printf("\n");
         */
         logData(data, i);
         state = FOUND;
      } else if ((data[i] < TRIGGER_VALUE) && (state == FOUND)) {
         state = READY;
      }
   }
}

int main(void) {
   unsigned short data[1000];
   int i;

   for (i=1; i<1000; i++) {
      if ((i%100 == 0) || (i>200 && i<400) || (i>600 && i<800))
         data[i] = 40000;
      else
         data[i] = 0;
   }

   detectLoudNoise(data);

   return 0;
}
