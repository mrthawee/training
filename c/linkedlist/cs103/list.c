#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
   int           data;
   struct node  *next;
};

/*
 * Build a linked list with 3 nodes; 1, 2, 3
 */
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

   return one;
}

/*
 * Print value of each node in a linked list.
 */
void Print(struct node *curr) {
   //while (curr != NULL) {
   while (curr) {
      printf("%d ", curr->data);
      curr = curr->next;
   }
   printf("\n");
}

/*
 * Free memory of each node in a linked list.
 */
void FreeList(struct node **headRef) {
   struct node *head = *headRef;
   struct node *curr = head;

   while (curr != NULL) {
      head = head->next;
      free(curr);
      curr = head;
   }

   *headRef = head;
}

/*
 * Count number of nodes of a linked list.
 */
int Length(struct node *head) {
   int count = 0;

   //while (head != NULL) {
   while (head) {
      count++;
      head = head->next;
   }

   return count;
}

/*
 * Create and add a new node with value 'data' to node 'curr'
 */
void Push(struct node **currRef, int data) {
   struct node *newNode = (struct node*)malloc(sizeof(struct node));

   assert(newNode != NULL);

   newNode->data = data;
   newNode->next = *currRef;

   *currRef = newNode;
}

void AddHead(struct node **headRef, int data) {
   Push(headRef, data);
}

void AddTail(struct node **tailRef, int data) {
   struct node *tail = *tailRef;

   Push(&(tail->next), data);
   tail = tail->next;

   *tailRef = tail;
}

void TestAddHeadAndAddTail() {
   struct node *tail = (struct node*)malloc(sizeof(struct node));
   struct node *head = tail;
   tail->data = 100;
   tail->next = NULL;
   Print(head);
   printf("Length = %d\n", Length(head));

   AddTail(&tail, 200);
   Print(head);
   printf("Length = %d\n", Length(head));

   AddTail(&tail, 300);
   AddHead(&head, 1);
   Print(head);
   printf("Length = %d\n", Length(head));

   FreeList(&head);
   Print(head);
   printf("Length = %d\n", Length(head));
}

void TestAddHead() {
   struct node *list = BuildOneTwoThree();
   Print(list);
   printf("Length = %d\n", Length(list));

   Push(&list, 5);
   Push(&list, 10);

   Print(list);
   printf("Length = %d\n", Length(list));

   FreeList(&list);
}

int main() {
   TestAddHeadAndAddTail();

//   TestAddHead();
}
