#include <stdio.h>
#include "ll_util.h"

struct node *AddAtHead(int numNodes) {
  struct node *head = NULL;
  int i;

  for (i=1; i<=numNodes; i++) {
    Push(&head, i);

    PrintLinkedList(head);
  }

  return head;
}

void main() {
  struct node *my_ll = BuildOneTwoThree();
  PrintLinkedList(my_ll);
  FreeLinkedList(my_ll);

  /*
  PrintLinkedList(my_ll);
  Push(&my_ll, 5);
  PrintLinkedList(my_ll);
  FreeLinkedList(my_ll);
  printf("\n\n");

  */
  my_ll = AddAtHead(10);
  PrintLinkedList(my_ll);
  FreeLinkedList(my_ll);

}
