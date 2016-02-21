#include <stdio.h>

int main(void)
{
   int my_array[] = {1,23,17,4,-5,100};
   int *ptr;

   ptr = &my_array[0]; /* point our pointer to the first element of the array */

   int i;
   for (i=0; i<6; i++)
   {
      printf("my_array[%d] = %3d ", i, my_array[i]);  
      /* printf("ptr + %d = %d\n", i, *(ptr+i)); */
      printf("  ptr + %d = %3d\n", i, *ptr++);
      /* printf("ptr + %d = %d\n", i, *(++ptr)); */
   }

   return 0;
}
