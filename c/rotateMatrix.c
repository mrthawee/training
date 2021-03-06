#include <stdio.h>


int main() {
   int x[3][3] = { { 1, 2, 3 },
                   { 4, 5, 6 },
                   { 7, 8, 9 } };

   int m[2][2] = { { 1, 2 }, 
                   { 4, 3 } };

   int i,j;
   for (i=0; i<2; i++) {
      for (j=0; j<2; j++) {
         printf("m[%d][%d] = %d\n", i, j, m[i][j]);
      }
   }

/*
   // 2 by 2
   m[0][0] -> m[0,1] 
   m[0][1] -> m[1,1]
   m[1][1] -> m[1,0]
   m[1][0] -> m[0,0]

   or 
   m2[0,0] <- m[1,0] , m2[0,1] <- m[0,0]
   m2[1,0] <- m[1,1] , m2[1,1] <- m[0,1]
   
   
   // 3 by 3
   m[0][0] -> m[0,2]
   m[0][1] -> m[1,2]
   m[0][2] -> m[2,2]

   m[1][2] -> m[2,1]
   m[2][2] -> m[2,0]

   m[2][1] -> m[1][0]
   m[2][0] -> m[0][0]
   m[1][0] -> m[0][1]


   or
   
   m2[0,0] <- m[2,0] , m2[0,1] <- m[1,0] , m2[0,2] <- m[0,0]
   m2[1,0] <- m[2,1] , m2[1,1] <- m[1,1] , m2[1,2] <- m[0,1]
   m2[2,0] <- m[2,2] , m2[2,1] <- m[1,2] , m2[2,2] <- m[0,2]
   
*/
   int m2[3][3];
   for (i=0; i<3; i++)
      for (j=0; j<3; j++)
      {
//         printf("%d,%d -> %d,%d\n", i, j, 2-j-1, i);
         m2[i][j] = x[3-j-1][i];
      }

   for (i=0; i<3; i++) {
      for (j=0; j<3; j++)
      {
//         printf("m2[%d][%d] = %d\n", i, j, m2[i][j]);
         printf("%d ", x[i][j]);
      }
      printf("\n");
   }

   printf("  |\n");
   printf("  V\n");
   for (i=0; i<3; i++) {
      for (j=0; j<3; j++)
      {
//         printf("m2[%d][%d] = %d\n", i, j, m2[i][j]);
         printf("%d ", m2[i][j]);
      }
      printf("\n");
   }
}
