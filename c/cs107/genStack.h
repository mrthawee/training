#ifndef GEN_STACK_H
#define GEN_STACK_H

typedef struct {
   void *elems;
   int   elemSize;
   int   logLength;
   int   allocLength;
} stack;

void StackNew(stack *s, int elemSize);
void StackDispose(stack *s);
void StackPush(stack *s, void *elemAddr); // take ptr to an elem
void StackPop(stack *, void *elemAddr);  // returning the ptr to the popped elem

#endif
