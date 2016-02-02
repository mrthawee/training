#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Node* head;

void PrintList() {
   int i=0;

   struct Node* tmp = head;

   printf("List: ");

   while (tmp != NULL) {
      printf("%d", tmp->data);
      tmp = tmp->next;
      if (tmp != NULL) {
         printf(", ");
      }
   }

   printf(" <eol>\n");
}

void PrintListRecursive(struct Node* head) {
   // if (head == NULL) {
   if (!head) {
      printf("<eol>\n");
      return;
   }
   printf("%d ", head->data);
   PrintListRecursive(head->next);
}

void PrintReversedListRecursive(struct Node* head) {
   if (!head) {
      printf("<eol> ");
      return;
   }
   PrintReversedListRecursive(head->next);
   printf("%d ", head->data);  // just print after the stack is popping
}

/* data : value to be inserted
   posN : position n(th) to be inserted (start from 1)
*/
void InsertNode(int data, int posN) {
   struct Node* tmp = (struct Node*)malloc(sizeof(struct Node*));
   // Node* tmp = new Node(); // in C++

   int i=0;
   struct Node* tmp2 = NULL;

   tmp->data = data;
   tmp->next = NULL;

   // posN = 1 : the beginning for the list
   if (posN == 1) {
      tmp->next = head;
      head = tmp;
   } else {
      tmp2 = head;
      for (i=0; i<posN-2; i++) {
         tmp2 = tmp2->next;
      }
      tmp->next = tmp2->next;
      tmp2->next = tmp;
   }

   PrintList();
}

void DeleteNode(int data) {
   struct Node* tmp = head;
   struct Node* tmp2 = NULL;

   if (head->data == data) {
      tmp = head;
      head = head->next;
      free(tmp);
   } else {
      tmp = head;
      while (tmp->next->data != data) {
         tmp = tmp->next;
      }
     
      tmp2 = tmp->next;
      tmp->next = tmp->next->next;
      free(tmp2);
   } 

   PrintList();
}

void DeleteNode2(int data) {
   struct Node* tmp = head;
   struct Node* tmp2 = NULL;

   if (head == NULL) {
      printf ("List is empty! Nothing to be deleted.\n");
   } else {
      if (head->data == data) {
         tmp = head;
         head = head->next;
         free(tmp);
      } else {
         tmp = head;
         while (tmp->next->data != data) {
            tmp = tmp->next;
            if (tmp->next == NULL) {
               printf ("End of List! Nothing to be deleted.\n");
               return;
            }
         }
     
         tmp2 = tmp->next;
         tmp->next = tmp->next->next;
         free(tmp2);
      }
   } 

   PrintList();
}

/*
Step 1: set curr to head
 prev head,curr
  |    |
 NULL [0]->[1]->[2]->NULL

Step 2: move head to head->next
 prev curr head
  |    |    |
 NULL [0]->[1]->[2]->NULL

Step 3: point curr to prev
 prev curr head
  |    |    |
 NULL<-[0] [1]->[2]->NULL

Step 4: move prev to curr
  prev,curr head
        |    |
 NULL<-[0]  [1]->[2]->NULL

Step 5: move curr to new head
       prev head,curr
        |     |
 NULL<-[0]   [1]->[2]->NULL
*/
void ReverseList() {
   struct Node* prev = NULL;
   struct Node* curr = head;

   while (head->next != NULL) {
      head = head->next;
      curr->next = prev;
      prev = curr;
      curr = head;
   }
   head->next = prev;

   PrintList();
}

void ReverseListRecursive(struct Node* p) {
   if (p->next == NULL) {
      head = p;
   } else {
      ReverseListRecursive(p->next);
      p->next->next = p;
      p->next = NULL;
   }
}

struct Node* reverse2(struct Node* p) {
   printf("push : ");
   printf("  p: ");
   PrintListRecursive(p);

   if (p->next == NULL) {
      return p;
   } 
   
   struct Node* new_head = reverse2(p->next);
   printf("pop: \n");
   printf("  new_head : ");
   PrintListRecursive(new_head);

   printf("  old p: ");
   PrintListRecursive(p);

   p->next->next = p;
   p->next = NULL;

   printf("  new p: ");
   PrintListRecursive(p);

   return (new_head); // reversed list
}

struct Node* reverse3(struct Node *head, struct Node* prev) {
   if (head->next == NULL) {
      head->next = prev;
      return head;
   }
   struct Node* new_head = reverse3(head->next, head);
   head->next = prev;

   return new_head;
}

int main() {
   head = NULL;
   
   printf("Hello!\n");

   InsertNode(2, 1);  // List: 2
   InsertNode(3, 2);  // List: 2, 3
   InsertNode(4, 1);  // List: 4, 2, 3
   InsertNode(5, 2);  // List: 4, 5, 2, 3

//   printf("Calling PrintListRecursive(head): ");
//   PrintListRecursive(head);

//   ReverseList();
   printf("Let's reverse the list with recursion!\n");
//   ReverseListRecursive(head); // ver 1 : reverse recursively + global head
//   head = reverse2(head);      // ver 2 : reverse recursively (1 arg)
   head = reverse3(head, NULL);  // ver 3 : reverse recursively (2 args)

   printf("Calling PrintListRecursive(head): ");
   PrintListRecursive(head);

   printf("Calling PrintReversedListRecursive(head): ");
   PrintReversedListRecursive(head); 

   printf("\n\n");

   ReverseList();

   DeleteNode(2);     // List: 4, 5, 3
   DeleteNode2(6);
   DeleteNode(4);     // List: 5, 3
   DeleteNode(3);     // List: 5
   DeleteNode(5);     // List: 5
   
}
