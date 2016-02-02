/*
 malloc - void* malloc(size_t size) where size_t is unsigned int
             returns the addr of the first byte of the allocated memory
             memory is uninitialized!

 calloc - void* calloc(size_t num, size_t size) : allocate and set to 0
          EX: calloc(3, sizeof(int)) 

 realloc - void* realloc(void* ptr, size_t size)
              *ptr - pointer to existing memory block
               size - size of the new block

NOTE:
realloc(A, 0); => equivalent to free A because size is set to 0
realloc(NULL, n*sizeof(int)); => equivalent to malloc because memory is newly allocated here

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n;

   printf("Enter size of array: ");
   scanf("%d", &n);

   /* ------ malloc ------ */
   int* A = (int*)malloc(n * sizeof(int)); // get uninitialized memory
   for (int i=0; i<n; i++)
   {
      A[i] = i+1;
   }

   for (int i=0; i<n; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");

   free(A);  // de-allocate memory
   A = NULL;

   /* ------ calloc ------ */
   A = (int*)calloc(n, sizeof(int));  // get initialized to 0 memory
   printf("sizeof(A) = %lu\n", sizeof(A));
   for(int i=0; i<n; i++)
   {
      A[i] = i * 2;
   }
   for (int i=0; i<n; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");

   free(A);  // de-allocate memory
   A = NULL;

   /* --- try reading after free --- */
   // This is crash since A has already set to NULL
/*
   A[2] = 123;
   for (int i=0; i<n; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");
*/

   A = (int*)malloc(n * sizeof(int));  // alloc n int
   int* B = (int*)realloc(A, 2*n*sizeof(int)); // realloc to 2*n int
   printf("sizeof(B) = %lu\n", sizeof(B));
   printf("addr of A = %p\n", A);
   printf("addr of B = %p\n", B);
   for (int i=0; i<2*n; i++)
   {
      printf("%d ", B[i]);
   }
   printf("\n");
   
   int* C = (int*)realloc(B, n*sizeof(int)/2); // relloc to n/2 int
   printf("sizeof(C) = %lu\n", sizeof(C));
   printf("addr of A = %p\n", A);
   printf("addr of B = %p\n", B);
   printf("addr of C = %p\n", C);
   for (int i=0; i<n/2; i++)
   {
      printf("%d ", C[i]);
   }
   printf("\n");

   free(C);
   
}
