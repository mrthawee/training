#include <stdio.h>

struct rec {
   int x, y, z;
};

int main(void) {
   int counter;
   FILE *ptr_myfile;
   struct rec my_record;

   ptr_myfile = fopen("test.bin", "wb");

   if (!ptr_myfile) {
      printf("Error: unable to open file.\n");
      return -1;
   } 

   for (counter=1; counter <= 10; counter++) {
      my_record.x = counter;
      my_record.y = counter*-1;
      my_record.z = 0;
      fwrite(&my_record, sizeof(struct rec), 1, ptr_myfile);
   }

   fclose(ptr_myfile);

   printf("Done.\n");

   return 0;
}
