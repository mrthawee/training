#include <stdio.h>

struct rec {
   int x, y, z;
};

int main(void) {
   int counter;
   FILE *fp;
   struct rec my_rec;

   short data = 01;

   fp = fopen("samples.bin", "rb");
   if (!fp) {
      printf("Error: unable to open file.\n");
      return -1;
   }

/*
   for (counter=1; counter <=10; counter++) {
      //fread(&my_rec, sizeof(struct rec), 1, fp);
      //printf("%d: x=%d y=%d z=%d\n", counter, my_rec.x, my_rec.y, my_rec.z);
   }
   */

   int cnt = 0;
//   while (!feof(fp)) {
   while (fread(&data, sizeof(data), 1, fp)) {
      printf("%hd ", data);
      cnt++;
   }
   printf("\n");
   printf("found %d samples\n", cnt);

   fclose(fp);

   return 0;
}
