#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "genStack.h"

/* static function : this function is available to this file ONLY!! */
static void StackGrow(stack *s) {
   s->elems = realloc(s->elems, s->allocLength * 2 * s->elemSize);
   assert(s->elems != NULL);
   s->allocLength *= 2;
}

void StackNew(stack *s, int elemSize) {
   assert(elemSize > 0);

   s->elems = malloc(4*elemSize);
   assert(s->elems != NULL);

   s->elemSize = elemSize;
   s->logLength = 0;
   s->allocLength = 4;
}

void StackDispose(stack *s) {
   free(s->elems);  // can handle only one level of pointers!!!
   s->elemSize = 0;
   s->logLength = 0;
   s->allocLength = 0;
}

void StackPush(stack *s, void *elemAddr) {
   if (s->logLength == s->allocLength) {
      StackGrow(s);
   }

   /* Find out where to start copying data into */
   void *target = (char*)s->elems + (s->logLength * s->elemSize);
   /* Copy data into */
   memcpy(target, elemAddr, s->elemSize);
   /* Increment element count by one */
   s->logLength++;
}

void StackPop(stack *s, void *elemAddr) {
   void *source = (char *)s->elems + (s->logLength - 1) * s->elemSize;
   memcpy(elemAddr, source, s->elemSize);
   s->logLength--;
}

main() {
   stack s;
   int size = 17;
   int arr[size];
   int i;
   for (i=0; i<size; i++) {
      arr[i] = i+1;
   }

   StackNew(&s, sizeof(int));
   for (i=0; i<size; i++) {
      StackPush(&s, &arr[i]);
   }

   for (i=0; i<size; i++) {
      int i;
      StackPop(&s, &i);
      printf("%d\n", i);
   }
   StackDispose(&s);

   stack strStack;
   char *friends[] = { "Al", "Bob", "Carl" };
   size = 3;
   StackNew(&strStack, sizeof (char *));
   for (i=0; i<size; i++) {
      char *copy = strdup(friends[i]); // malloc happens here!
      StackPush(&strStack, &copy);
   }

   for (i=0; i<size; i++) {
      char *name;
      StackPop(&strStack, &name);
      printf("%s\n", name);
      free(name);  // so, we need to 'free' here!!
   }

   StackDispose(&strStack);
}
