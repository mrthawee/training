#include <stdio.h>
#include "ll_util.h"

/*********************************
 * Prob 1: Count node with val N
 *********************************/
int Count(struct node *head, int searchFor) {
  int cnt = 0;
  while (head) {
    if (head->data == searchFor) {
      cnt++;
    }
    head = head->next;
  }

  return cnt;
}

void CountTest() {
  printf("\nProb 1: Count node with val N\n");
  struct node *ll = BuildOneTwoThree();

  int i;
  for (i=0; i<5; i++) {
    int c = Count(ll, i);
    printf("Count %d found %d\n", i, c);
  }
}


/*********************************
 * Prob 2: Get val of node Nth
 ********************************/
int GetNth(struct node *head, int index) {
  int cnt = 0;
  while (head) {
    if (index == cnt) {
      return head->data;
    }
    head = head->next;
    cnt++;
  }

  return -999;  /* not found */
}

void GetNthTest() {
  printf("\nProb 2: Get val of node Nth\n");
  struct node * ll = BuildOneTwoThree();
  int i;
  for (i=0; i<5; i++) {
    int c = GetNth(ll, i);
    printf("GetNth %d found %d\n", i, c);
  }
}


/***********************************************************************
 * Prob 3: Delete List - deallocate all nodes and set its head to NULL
 ***********************************************************************/

void DeleteList(struct node **headRef) {
  struct node* head = *headRef;
  struct node* curr = head;

  while (curr) {
    head = head->next;
    free(curr);
    curr = head;
  }
  *headRef = curr;
}

void DeleteListTest() {
  printf("\nProb 3: delete list - deallocate all nodes and set head to NULL\n");
  struct node * ll = BuildOneTwoThree();

  PrintLinkedList(ll);
  DeleteList(&ll);
  PrintLinkedList(ll);
}


/**************************************************************************************
 * Prob 4: Pop 
 *  - for non-empty list, delete the head node and return val of that node
 *  - it is the reverse of Push() - add new node to head
 **************************************************************************************/
int Pop(struct node **headRef) {
  struct node *head = *headRef;
  int val = -999; // not found - list is empty
  
  if (head) {
    val = head->data;
    struct node *pop_node = head;
    *headRef = head->next;
    free(pop_node);
  }

  return val;
}

void PopTest() {
  printf("\nProb 4: Pop List: if list is not empty, delete head node and return its val\n");
  struct node * head = BuildOneTwoThree();

  while (head) {
    int val = Pop(&head);
    printf("pop val = %d\n", val);
  }
}


/******************************************************
 * Prob 5: Insert Nth - insert new node at Nth index
 *    - N = 0 .. lenght of list
 *****************************************************/

void InsertNth(struct node **headRef, int index, int data) {
  struct node *curr = *headRef;
  int curr_index_cnt = 0;

  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  if (!curr && !index) {
    *headRef = new_node;
    return;
  } else {
    while (curr)
      if (curr_index_cnt+1 == index) {
        new_node->next = curr->next;
        curr->next = new_node;
        return;
      } else {
        curr = curr->next;
        curr_index_cnt++;
    } 
  }

  printf("index=%d, curr_index_cnt=%d at end of list : no insertion\n", index, curr_index_cnt);
  free(new_node);  // index is out of range; no insertion
}

void InsertNthTest() {
  printf("\nProb 5: insert new node at Nth index if Nth is in range of 0 - list length\n");
  struct node * head = NULL;

  InsertNth(&head, 0, 13);  // insert head
  PrintLinkedList(head);
  InsertNth(&head, 1, 42);  // insert tail
  PrintLinkedList(head);
  InsertNth(&head, 1, 5);   // insert middle
  PrintLinkedList(head);
  InsertNth(&head, 10, 99);   // insert middle
  PrintLinkedList(head);

  DeleteList(&head);
  PrintLinkedList(head);
}


/*************************************************************
 * Prob 6: SortedInsert - insert new node into a sorted list
 ************************************************************/
void SortedInsert(struct node** headRef, struct node *newNode) {
  struct node *head = *headRef;
  struct node *curr = head;

  if (!newNode) {
    return;
  }

  if (!head) {
    *headRef = newNode;
    return;
  } else if (head->data > newNode->data) {
    newNode->next = head;
    *headRef = newNode;
    return;
  }

  while (curr && curr->data < newNode->data) {
    if (!curr->next) {
      curr->next = newNode;
      return;
    } else if (curr->next->data >= newNode->data) {
      newNode->next = curr->next;
      curr->next = newNode;
      return;
    }
    curr = curr->next;
  }

  // no need to update *headRef since it points to the same head
}


void SortedInsertTest() {
  printf("\nProb 6: Sorted Insert\n");
  struct node * head = BuildOneTwoThree();
  PrintLinkedList(head);

  struct node *new_node_1 = (struct node*)malloc(sizeof(struct node));
  new_node_1->data = 10;
  new_node_1->next = NULL;
  SortedInsert(&head, new_node_1);
  PrintLinkedList(head);

  struct node *new_node_2 = (struct node*)malloc(sizeof(struct node));
  new_node_2->data = -2;
  new_node_2->next = NULL;
  SortedInsert(&head, new_node_2);
  PrintLinkedList(head);

  struct node *new_node_3 = (struct node*)malloc(sizeof(struct node));
  new_node_3->data = 7;
  new_node_3->next = NULL;
  SortedInsert(&head, new_node_3);
  PrintLinkedList(head);

  DeleteList(&head);
  PrintLinkedList(head);
}


/*********************************************************************************
 * Prob 7: InsertSort() - rearrange nodes in sorted order - using SortedInsert()
 ********************************************************************************/
void InsertSort(struct node **headRef) {
  struct node *head = *headRef;
  struct node *curr = head;
  struct node *sorted_list = NULL;
  struct node *tmp = NULL;

  while (curr) {
    tmp = curr;
    curr = tmp->next;
    tmp->next = NULL;
    SortedInsert(&sorted_list, tmp);
  }

  *headRef = sorted_list;
}

void InsertSortTest() {
  printf("Prob 7: Insert Sort - rearrange nodes to sorted order\n");

  struct node *new_node_1 = (struct node*)malloc(sizeof(struct node));
  struct node *new_node_2 = (struct node*)malloc(sizeof(struct node));
  struct node *new_node_3 = (struct node*)malloc(sizeof(struct node));
  new_node_1->data = 10;
  new_node_1->next = new_node_2;
  new_node_2->data = -2;
  new_node_2->next = new_node_3;
  new_node_3->data = 7;
  new_node_3->next = NULL;
  PrintLinkedList(new_node_1);

  InsertSort(&new_node_1);
  PrintLinkedList(new_node_1);

  DeleteList(&new_node_1);
  PrintLinkedList(new_node_1);
}


/**********************************
 * Prob 8 Append 2 lists
 *********************************/
void Append(struct node **aRef, struct node **bRef) {
  struct node *aCurr = *aRef;

  if (!aCurr) {
    *aRef = *bRef;
  } else { 
    while (aCurr->next) {
      aCurr = aCurr->next;
    }
    aCurr->next = *bRef;
  }
  *bRef = NULL;
}

void AppendTest() {
  printf("Prob 8: Append 2 lists\n");
  struct node *a = BuildOneTwoThree();
  struct node *b = BuildOneTwoThree();
  Append(&a, &b);
  PrintLinkedList(a);
  DeleteList(&a);

  a = BuildOneTwoThree();
  b = NULL;
  Append(&a, &b);
  PrintLinkedList(a);
  DeleteList(&a);

  a = NULL;
  b = BuildOneTwoThree();
  Append(&a, &b);
  PrintLinkedList(a);
  DeleteList(&a);
}


/***********************************
 * Prob 9: FrontBackSplit
 **********************************/
void FrontBackSplit(struct node* source, struct node **frontRef, struct node **backRef) {
  if (!source || !source->next) {
    *frontRef = source;
    *backRef = NULL;
  }

  struct node *slow = source;
  struct node *fast = source->next; // so, slow will always point at last node of front

  while (fast) {
    fast = fast->next;
    if (fast) {
      fast = fast->next;
      slow = slow->next;  // slow is moved ONLY IF fast makes 2 moves
    }
  }

  *frontRef = source;
  *backRef = slow->next; // since slow is at last node of front
  slow->next = NULL;
}

void FrontBackSplitTest() {
  printf("\nProb 9: Front Back Split - front takes the mid node for odd num nodes\n");
  struct node *a = (struct node*)malloc(sizeof(struct node));
  struct node *b = (struct node*)malloc(sizeof(struct node));
  struct node *c = (struct node*)malloc(sizeof(struct node));
  /*
  struct node *d = (struct node*)malloc(sizeof(struct node));
  struct node *e = (struct node*)malloc(sizeof(struct node));
  */

  a->data = 1;
  a->next = b;
  b->data = 2;
  b->next = c;
  c->data = 3;
  c->next = NULL;
  /*
  c->next = d;
  d->data = 4;
  d->next = e;
  e->data = 5;
  e->next = NULL;
  */

  PrintLinkedList(a);
  struct node *front = NULL;
  struct node *back = NULL;
  FrontBackSplit(a, &front, &back);
  PrintLinkedList(front);
  PrintLinkedList(back);

  DeleteList(&front);
  DeleteList(&back);
}

void main() {
//  CountTest();
//  GetNthTest();
//  DeleteListTest();
//  PopTest();
//  InsertNthTest();

//  SortedInsertTest();
//  InsertSortTest();
//  AppendTest();
  FrontBackSplitTest();
}
