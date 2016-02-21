#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
   int data;
   struct node *next;
};

struct node* BuildOneTwoThree() {
   struct node *one, *two, *three;

   one = (struct node*)malloc(sizeof(struct node));
   two = (struct node*)malloc(sizeof(struct node));
   three = (struct node*)malloc(sizeof(struct node));

   assert(one != NULL);
   assert(two != NULL);
   assert(three != NULL);

   one->data = 1;
   one->next = two;
   two->data = 2;
   two->next = three;
   three->data = 3;
   three->next = NULL;

   return one;
}

int Length(struct node *head) {
   int cnt = 0;
   while (head != NULL) {
      cnt++;
      head = head->next;
   }
   return cnt;
}

void Print(struct node *head) {
   struct node *curr = head;
   while (curr != NULL) {
      printf("%d ", curr->data);
      curr = curr->next;
   }
   printf("\n");
}

void Push(struct node **headRef, int newData) {
   struct node *head = *headRef;
   struct node *n = (struct node*)malloc(sizeof(struct node));
   n->data = newData;
   n->next = head; 

   head = n;
   *headRef = head;  // Update the "head" of caller function
}

// nth : 0 to Lenght-1
int GetNth(struct node *head, int nth) {
   int i;
   for (i=0; i<nth; i++)
      head = head->next;
   return head->data;
}

void DeleteList(struct node **headRef) {
   struct node *head = *headRef;
   struct node *curr = head;
   while (curr != NULL) {
      head = curr->next;
      free(curr);
      curr = head;
   }
   *headRef = head;
}

int Pop(struct node **headRef) {
   struct node *head = *headRef;
   struct node *curr = head;
   int data = -1;
   if (head == NULL) {
      printf("Pop: found head is NULL\n");
   } else {
      data = curr->data;
      head = curr->next;
      free(curr);
      *headRef = head;
   }

   return data;
}
      
void InsertNth(struct node **headRef, int idx, int v) {
   struct node *head = *headRef;
   struct node *curr = head;

   struct node *n = (struct node*)malloc(sizeof(struct node));
   n->data = v;
//   n->next = NULL;

   if (idx > 0) {
      while (idx-1 > 0) {
         curr = curr->next;
         idx--;
      }
      n->next = curr->next; 
      curr->next = n;
   } else {
      n->next = head; 
      head = n;
   }

   *headRef = head;  // Update the "head" of caller function
}

void SortedInsert(struct node **headRef, struct node *newNode) {
/*
   struct node **currRef = headRef;

   while (*currRef != NULL && (*currRef)->data < newNode->data) {
      currRef = &((*currRef)->next);
   }

   newNode->next = *currRef;
   *currRef = newNode;
*/
   // Insert to the front for current head
   if (*headRef == NULL || (*headRef)->data >= newNode->data) {
      newNode->next = *headRef;
      *headRef = newNode;
   } else { // Insert to elsewhere (non-head)
      // Locate the node before the point of insertion
      struct node *curr = *headRef;
      while (curr->next != NULL && curr->next->data < newNode->data) {
         curr = curr->next;
      }
      newNode->next = curr->next;
      curr->next = newNode;
   }
}

void InsertSort(struct node **headRef) {
   struct node *newHead = NULL;
   struct node *curr = *headRef;
   struct node *next;

   while (curr != NULL) {
      next = curr->next;
      SortedInsert(&newHead, curr);
//      Print(newHead);
      curr = next;
   }

   *headRef = newHead;
}

void Append(struct node **aRef, struct node **bRef) {
   if (*aRef == NULL) {
      *aRef = *bRef;
   } else {
/* Can't move with (*aRef) directly because it will change the head of aRef 
      while ((*aRef)->next != NULL) {
         (*aRef) = (*aRef)->next;
      }
      (*aRef)->next = *bRef;
*/
      // Create 'curr' local variable to point to head of aRef
      // And travel with curr, so it won't change the head of aRef
      struct node *curr = *aRef;
      while (curr->next != NULL) {
         curr = curr->next;
      }
      curr->next = *bRef;
   }
   *bRef = NULL;
}

void FrontBackSplit(struct node *src, struct node **fRef, struct node **bRef) {
   int len = Length(src);

   if (len < 2 ) {
      *fRef = src;
      *bRef = NULL;
   } else {
      int half = len/2;  // fRef will have #Nodes = half
//      printf("half = %d\n", half);

      *fRef = src;
      while (half-1 > 0) {
         // traverse with 'src' is fine because it was passed in by value
         //    => same as a local variable
         src = src->next;
         half--;
      }
      *bRef = src->next;
      src->next = NULL;
   }
}

void Reverse(struct node** headRef) {
   struct node *prev = NULL;
   struct node *head = *headRef;
   struct node *curr = head;

   if (head == NULL || head->next == NULL)
      return;

   while (head != NULL) {
      head = head->next;
      curr->next = prev;
      prev = curr;
      curr = head;
   }

   *headRef = prev;
}

void RecursiveReverse(struct node **headRef) {
   if (*headRef == NULL) {
      return;
   }

   struct node *head = *headRef;
   struct node *rest = head->next;

   if (rest == NULL) {
      return;
   }

   RecursiveReverse(&rest);

   // Re-wind the 2nd->next to 1st and 1st->next to NULL
   head->next->next = head;  // point original rest->next back to head
   head->next = NULL;        // point head->next to NULL : head becomes tail

   // Right now, rest is the updated new head
   *headRef = rest;          // point updated new head to caller headRef
}

int main(void) {
   struct node *head = BuildOneTwoThree();

   Print(head);

   Push(&head, 5);
   Print(head);
   Push(&(head->next->next), 10);
   Print(head);

   int v = GetNth(head, 3);
   printf("GetNth(head,3) = %d\n", v);

   v = Pop(&head);
   printf("Pop(&head) = %d\n", v);
   Print(head);

   printf("InsertNth(&head, 3, 99): ");
   InsertNth(&head, 3, 99);
   Print(head);

   printf("InsertNth(&head, 0, 77): ");
   InsertNth(&head, 0, 77);
   Print(head);

   printf("SortedInsert(&head, newNode(4)): ");
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = 4;
//   newNode->next = NULL;
   SortedInsert(&head, newNode);
   Print(head);

   printf("InsertSort(&head): ");
   InsertSort(&head);
   Print(head);

   printf("DelelteList(head): ");
   DeleteList(&head);
   Print(head);

   struct node *l1 = NULL;
   struct node *l2 = NULL;
   Push(&l1,2);
   Push(&l1,1);
   printf("l1: ");
   Print(l1);

   Push(&l2,4);
   Push(&l2,3);
   printf("l2: ");
   Print(l2);

   printf("Append:(&l1, &l2): ");
   Append(&l1, &l2);
   Print(l1);
   Print(l2);
   printf("Push(&l1, 5): ");
   Push(&l1, 5);    
   Print(l1);

   printf("Reverse List: ");
   Reverse(&l1);
   Print(l1);

   printf("FrontBackSplit(l1, &l1, &l2): \n");
   FrontBackSplit(l1, &l1, &l2);
   printf("  l1: ");
   Print(l1);
   printf("  l2: ");
   Print(l2);

   printf("RecursiveReverse l1 : ");
   RecursiveReverse(&l1);
   Print(l1);

   printf("RecursiveReverse l2 : ");
   RecursiveReverse(&l2);
   Print(l2);

   DeleteList(&l1);
   DeleteList(&l2);
}
