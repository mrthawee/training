#ifndef __LL_UTIL_H__
#define __LL_UTIL_H__

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

void PrintLinkedList(struct node *head) {
  printf("Linked List: ");
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int Length(struct node* head) {
  int cnt = 0;

  while (head) {
    head = head->next;
    cnt++;
  }

  return cnt;
}

struct node* BuildOneTwoThree() {
  struct node *one = (struct node*)malloc(sizeof(struct node));
  struct node *two = (struct node*)malloc(sizeof(struct node));
  struct node *tri = (struct node*)malloc(sizeof(struct node));

  one->data = 1;
  one->next = two;
  two->data = 2;
  two->next = tri;
  tri->data = 3;
  tri->next = NULL;

  return one;
}

struct node* FreeLinkedList(struct node *head) {
  struct node *curr = head;

  while (head) {
    head = head->next;
    free(curr);
    curr = head;
  }

  return head;
}

void Push(struct node** headRef, int newData) {
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = newData;
  
  new_node->next = *headRef;

  *headRef = new_node;
}


#endif
