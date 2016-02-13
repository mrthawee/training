#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   FILE *fp;

   if (argc < 3) {
      printf("Usage: %s <number of samples> <filename>\n", argv[0]);
      return -1;
   }

   int nSamples = atoi(argv[1]);
   char filename[100] = "\0";
   strcpy(filename, argv[2]);

   printf("nSamples = %d\n", nSamples);
   printf("Output file name = %s\n", filename);

//   fp = fopen("test.txt", "w");
   fp = fopen("samples.bin", "wb");
   if (!fp) {
      printf("Error: fail to open file\n");
      exit(-1);
   }

   int i = 0;
   short data = 0;

   for (i=1; i<=nSamples; i++) {
      if (i%100 == 0)
      //if ((i%100 == 0) || (i>200 &&i < 400))
         data = 40000;
      else 
         data = i%10;
      //printf("%d:%d ", i, data);
//      fprintf(fp,"%hd ",  data);
      fwrite(&data, sizeof(data), 1, fp);
   }

   fclose(fp);
   
   return 0;
}
