#include <stdio.h>

//int GetSize(int data[]) {
int GetSize(int *data) {
   return sizeof(data);
}

int main(int argc, char* argv[]) {
   int d1[] = { 1, 2, 3, 4, 5 };
   int s1= sizeof(d1);

   int* d2 = d1;
   int  s2 = sizeof(d2);

   int s3 = GetSize(d1);

   printf("s1=%d  s2=%d  s3=%d\n", s1, s2, s3);
   return 0;
} 
