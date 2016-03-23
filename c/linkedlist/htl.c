#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NUM_NODES 5

typedef struct node {
   int          data;
   struct node *next;
} NodeType;

NodeType *tmpNodeList = NULL;

int nMalloc = 0;
int nFree = 0;

NodeType *CreateNode(int val) {
   NodeType *newNode = NULL;
   if (tmpNodeList == NULL) {
      newNode = (NodeType *)malloc(sizeof(NodeType));
      nMalloc++;
      assert(newNode != NULL);
   } else {
      newNode = tmpNodeList;
      tmpNodeList = tmpNodeList->next; 
   }
   
   newNode->data = val;
   newNode->next = NULL;
}

void DeleteNode(NodeType *node) {
   if (node != NULL) {
      node->next = tmpNodeList;
      tmpNodeList = node;
   }
}

void InsertFront(NodeType **headRef, NodeType **tailRef,int  val) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;
/*
   NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));
   assert(newNode != NULL);
   newNode->data = val;
   newNode->next = NULL;
*/
   NodeType *newNode = CreateNode(val);

   if (head == NULL) {
      head = tail = newNode;
   } else {
      newNode->next = head;
      head = newNode;
   }

   *headRef = head;
   *tailRef = tail;
}

void InsertBack(NodeType **headRef, NodeType **tailRef,int val) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;
/*
   NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));
   assert(newNode != NULL);
   newNode->data = val;
   newNode->next = NULL;
*/
   NodeType *newNode = CreateNode(val);

   if (head == NULL) {
      head = tail = newNode;
   } else {
      tail->next = newNode;
      tail = newNode;
   }

   *headRef = head;
   *tailRef = tail;
}

void InsertSort(NodeType **headRef, NodeType **tailRef, int val) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;

   if (head == NULL) {
      NodeType *newNode = CreateNode(val);
      head = tail = newNode;
   } else if (head->data >= val) {
      InsertFront(&head, &tail, val);
   } else if (tail->data <= val) {
      InsertBack(&head, &tail, val);
   } else {
      NodeType *newNode = CreateNode(val);
      NodeType *curr = head;
      while ((curr->next != NULL) & (curr->next->data < val)) {
         curr = curr->next; 
      }
      newNode->next = curr->next;
      curr->next = newNode;
   }

   *headRef = head;
   *tailRef = tail;
}

void DeleteFront(NodeType **headRef, NodeType **tailRef, int val) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;
   NodeType *curr = NULL;

   if (head == NULL)
      return;

   if (head->next == tail) {
      curr = head;
      head = head->next;
//      free(curr);
      DeleteNode(curr);
   }
}

//void DeleteBack(int val) {
//}


void PrintList(NodeType *curr) {
   while (curr != NULL) {
      printf("%d ", curr->data);
      curr = curr->next;
   }
}
      
void DisposeList(NodeType **headRef, NodeType **tailRef) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;
   NodeType *curr = head;
   while (head != NULL) {
      curr = head;
      head = head->next;
      free(curr);
      nFree++;
//      DeleteNode(curr);
   }

   head = tail = NULL;

   *headRef = head;
   *tailRef = tail; 
}



int main(void) {

   NodeType *head = NULL;
   NodeType *tail = NULL;

   int i,n; 
   for (i=0; i<20; i+=2) {
      InsertBack(&head, &tail, i+1);
   }

   for (i=1; i<20; i+=2) {
      InsertSort(&head, &tail, i+1);
   }

   PrintList(head);
   DisposeList(&head, &tail);

   printf("nMalloc = %d\n", nMalloc);
   printf("nFree = %d\n", nFree);
}
