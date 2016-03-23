#include <stdlib.h>
#include "node.h"

struct node* BuildOneTwoThree() {
   struct node *one = (struct node*)malloc(sizeof(struct node));
   struct node *two = (struct node*)malloc(sizeof(struct node));
   struct node *three = (struct node*)malloc(sizeof(struct node));

   one->data = 1;
   one->next = two;

   two->data = 2;
   two->next = three;

   three->data = 3;
   three->next = NULL;

   return (one);
}
