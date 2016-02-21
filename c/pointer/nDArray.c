#include <stdio.h>
#include <string.h>

// *(A+i) is the same as  A[i]
//  (A+i) is the same as &A[i]
int A[5];

int B[2][3] = { {2, 3, 4},
                {5, 6, 7} }; 
// B[0] has 3 * 4 = bytes Ex addr 400 - 411
// B[1] has 3 * 4 = bytes Ex addr 412 - 423
// print B is the same as print &B[0]
// print *B is the same as B[0] or &B[0][0]
// print B+1 <=> &B[1]  // addr 412
// print *(B+1) <=> B[1] <=> &B[1][0] // addr 412
// print *(B+1)+2 <=>B[1]+2 <=> &B[1][2]  // addr 420
// print *(*B+1) <=> B[1][0] = 5 
// print *(*B)+1 <=> B[0][1] = 3 
// print (*(*B))+1 <=> B[0][1] = 3 

// B[i][j] = *(B[i] + j) = *(*(B+i) + j) 

int main()
{
   printf("B = %p\n", B);   // addr 400

   printf("*B = %p\n", *B);   // addr 400

   printf("B+1 = %p\n", B+1); // addr 400 + (size of 1-D array of 3 int or 412

   printf("*(*(B+1)) = %d\n", *(*(B+1)));
   printf("*(*(B+1)+2) = %d\n", *(*(B+1)+2));

//   printf("*((*B)+1) = %d\n", *(*(B)+1));
//   printf("(*(*B))+1 = %d\n", (*(*B))+1);

   int i,j;
   for(i=0; i<2; i++)
      for(j=0; j<3; j++)
      {
         printf(" B[%d][%d] = %d \n", i, j, B[i][j]);
         printf(" *(B[%d]+%d) = %d \n", i, j, *(B[i]+j));
         printf(" *(*(B+%d)+%d) = %d \n", i, j, *(*(B+i)+j));
      }
 
   return 0;
}
