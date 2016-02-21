#include <stdio.h>

void Func1DAryArg(int* A);   // 1-D Array as argument
void Func2DAryArg1(int* A[3]);    // 2-D Array - need clearly defined [3] 
void Func2DAryArg2(int  A[][3]);  // 2-D Array - need clearly defined [3]
void Func3DAryArg2(int  A[][2][2]);  // 3-D Array - need clearly defined [2][2]

int main()
{
   int C[3][2][2] = { { {2,5}, {7,9}},
                      { {3,4}, {6,1}},
                      { {0,8}, {11,13}} };

   printf("C = %p\n", C);
   printf("*C= %p\n", *C);
   printf("C[0] = %p\n", C[0]);
   printf("&C[0][0] = %p\n", &C[0][0]);

   printf("*(C[0][0]+1) = %d\n", *(C[0][0]+1)); // C[0][0][1]

   int A[2] = {1,2};
   int B[2][3] = { {2,4,6},{5,7,9}}; // So, B = int (*)[3] -> ptr to [3]

   Func1DAryArg(A); // OK
   Func2DAryArg(B); // OK since B = *B[3] or B[][3]

   int X[5][4];    // Can't call Func2DAryArg(X) - X is *[][4]

   Func3DAryArg(C); // OK - C is *C[2][2] or C[][2][2]
}
