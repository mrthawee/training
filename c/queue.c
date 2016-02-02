#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Node *front, *rear;

int  isQEmpty();
void EnQ(int val);
int  DeQFromRear();
void PrintQ();

// return 0 if not empty
int isQEmpty() {
   int isEmpty = 0; // false - not empty
   if (front == NULL) {
      isEmpty = 1; // true - empty
   }

   return isEmpty;
}

void EnQ(int val) {
   struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
   
   if (tmp == NULL) {
      printf("Error: can't malloc!\n");
      exit(1);
   }

   tmp->data = val;
   tmp->next = NULL;

   if ((front == NULL) & (rear == NULL)) {
      front = rear = tmp;
   } else {
      /*
      struct Node *curr = front;
      while (curr->next != NULL) 
         curr = curr->next;
      curr->next = tmp;
      */
      rear->next = tmp;
      rear = rear->next;
   }

   PrintQ();
}

int DeQFront() {
   int val = -1;
   if (front != NULL) {
      struct Node *tmp = front;
      val = tmp->data;
      front = front->next;
      free(tmp);
      if (front == NULL)
         rear = NULL;
   }

   return val;
}

int DeQFromRear() {
   int val = -1;

//   if (isQEmpty() != 0 ) {
   if (front != NULL) {
      struct Node *tmp = front;
      while (tmp->next->next != NULL) {
         tmp = tmp->next;
      }

      struct Node *last = tmp->next;
      val = last->data;
      free(last);
      tmp->next = NULL;
   }

   return val;
}

void PrintQ() {
   struct Node* curr = front;
   while (curr != NULL) {
      printf("%d ", curr->data);
      curr = curr->next;
   }
   printf("\n");
}

int main(int argc, char *argv[]) {

   int d[] = { 2, 4, 6, 8, 10 };

   front = rear = NULL;

   for (int i=0; i<5; i++) {
      EnQ(d[i]);
   }

   for (int i=0; i<5; i++) {
      //int v = DeQFromRear();
      //printf("DeQFromRear: %d\n", v);
      int v = DeQFront();
      printf("DeQFront: %d\n", v);
      PrintQ();
   }
   return 0;
}
