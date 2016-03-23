#ifndef INT_STACK_H
#define INT_STACK_H
typedef struct {
   int logicalLength;
   int allocLength;
   int *elems;
} stack;

void StackNew(stack *s);
void StackDispost(stack *s);
void StackPush(stack *s, int value);
int  StackPop(stack *s);

#endif /* INT_STACK_H */
