#include <stdio.h>

struct rec {
   int x, y, z;
};

int main(void) {
   int counter;
   FILE *ptr_myfile;
//   struct rec my_record;
   short data;

   ptr_myfile = fopen("test.txt", "w");

   if (!ptr_myfile) {
      printf("Error: unable to open file.\n");
      return -1;
   } 

   for (counter=1; counter <= 20; counter++) {
      /*
      my_record.x = counter;
      my_record.y = counter*-1;
      my_record.z = 0;
      */
      data = counter*-1;
      //fwrite(&my_record, sizeof(struct rec), 1, ptr_myfile);
      //fprintf(ptr_myfile,"%d %d %d\n", my_record.x, my_record.y, my_record.z);
      fprintf(ptr_myfile,"%hd ", data);
   }

   fclose(ptr_myfile);

   printf("Done.\n");

   return 0;
}
