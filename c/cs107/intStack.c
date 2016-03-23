#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "intStack.h"
/*
typedef struct {
   int logicalLength;
   int allocLength;
   int *elems;
} stack;

void StackNew(stack *s);
void StackDispost(stack *s);
void StackPush(stack *s, int value);
int  StackPop(stack *s);
*/

void StackNew(stack *s) {
   s->elems = malloc(4*sizeof(int));
   assert(s->elems != NULL);

   s->logicalLength = 0;
   s->allocLength = 4;
}

void StackDispose(stack *s) {
   free(s->elems);

   s->logicalLength = 0;
   s->allocLength = 0;
}

void StackPush(stack *s, int value) {
   if (s->logicalLength == s->allocLength) {
      s->elems = realloc(s->elems, 2*s->allocLength*sizeof(int)); // double the size
      assert(s->elems != NULL);
      s->allocLength *= 2;
   }

   s->elems[s->logicalLength] = value;
   s->logicalLength++;
}

int StackPop(stack *s) {
   assert(s->logicalLength > 0);
   --s->logicalLength;
   return s->elems[s->logicalLength];
}

main(){
   stack s;
   StackNew(&s);
   StackPush(&s, 1);
   StackPush(&s, 2);
   StackPush(&s, 3);
   StackPush(&s, 4);
   StackPush(&s, 5);
   int v = StackPop(&s);
   printf("%d\n",v);
   v = StackPop(&s);
   printf("%d\n",v);
   v = StackPop(&s);
   printf("%d\n",v);
   v = StackPop(&s);
   printf("%d\n",v);

   StackDispose(&s);
}
