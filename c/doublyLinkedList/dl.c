#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_NODES 5

typedef unsigned char   uint8;
typedef unsigned short  uint16;

typedef struct node {
   uint16       data;
   struct node *prev;
   struct node *next;
} Node;

Node *CreateNode(uint16 val) {
   Node *newNode = (Node *)malloc(sizeof(Node));
   assert(newNode != NULL);
   newNode->data = val;
   newNode->prev = NULL;
   newNode->next = NULL;
}


void InsertFront(Node **headRef, uint16 val) {
   Node *head = *headRef;
   Node *newNode = CreateNode(val);
   
   newNode->next = head;
   head = newNode;
}
   

int main(void) {
   Node *dlListHead = NULL;
   Node *dlListTail = NULL;

   for (i=0; i<NUM_NODES; i++) {
      InsertNode(&dlList, i+1);
   }

}
   
