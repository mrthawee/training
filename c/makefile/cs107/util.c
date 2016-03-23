#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void PrintList(struct node *head, char *str)
{
   if (str != NULL)
      printf("List %s : ", str);

   while (head != NULL) {
      printf("%d ", head->data);
      head = head->next;
   }
   printf("\n");
}
