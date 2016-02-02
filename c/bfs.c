#include <stdio.h>
#include <stdlib.h>

typedef struct BNodeType {
   struct BNodeType *left;
   struct BNodeType *right;
   int               data;
} BNode;

struct Node {
//   int data;
          BNode* bNode;
   struct Node*  next;
};

struct Node *front, *rear;

//int  isQEmpty();
//void EnQ(int val);
void EnQ(BNode *bNode);

//int  DeQFromRear();
void PrintQ();

// return 0 if not empty
/*
int isQEmpty() {
   int isEmpty = 0; // false - not empty
   if (front == NULL) {
      isEmpty = 1; // true - empty
   }

   return isEmpty;
}
*/

void EnQ(BNode* val) {
   struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
   
   if (tmp == NULL) {
      printf("Error: can't malloc!\n");
      exit(1);
   }

   tmp->bNode = val;
   tmp->next = NULL;

   if ((front == NULL) & (rear == NULL)) {
      front = rear = tmp;
   } else {
      rear->next = tmp;
      rear = rear->next;
   }

//   PrintQ();
}

BNode* DeQFront() {
   BNode* val = NULL;
   if (front != NULL) {
      struct Node *tmp = front;
      val = tmp->bNode;;
      front = front->next;
      free(tmp);
      if (front == NULL)
         rear = NULL;
   }

   return val;
}

/*
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
*/

void PrintQ() {
   struct Node* curr = front;
   while (curr != NULL) {
      printf("%d ", curr->bNode->data);
      curr = curr->next;
   }
   printf("\n");
}

/*
void testQueue() {
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
}
*/

void InsertBinTree(BNode** top, BNode* new) {
   if ((*top) != NULL) {
      printf("top->data=%d : add new->data=%d\n", (*top)->data, new->data);
   } else {
      printf("top = NULL : add new->data=%d\n", new->data);
   }

   if ((*top) == NULL) {
      *top = new;
   } else if ((*top)->data > new->data) { // insert left
      printf("go left, ");
      InsertBinTree(&(*top)->left, new);
   } else if ((*top)->data <= new->data) {
      printf("go right, ");
      InsertBinTree(&(*top)->right, new);
   }
}

// DFS - infix
void DFSBinTree(BNode *top) {
   if (top != NULL) {
      if (top->left != NULL) {
         DFSBinTree(top->left);
      }
      printf(" %d ", top->data);
      if (top->right != NULL) {
         DFSBinTree(top->right);
      }
   }
}

void BFSBinTree(BNode *top) {
   BNode *val;
   if (top != NULL) {
      EnQ(top);

/*
      printf("Q: ");
      PrintQ();
      printf("\n");
*/

      while (front != NULL) {      
         val = DeQFront();
         //printf("found bNode->data=%d\n", val->data);
         printf(" %d ", val->data);
         if (val->left != NULL)
            EnQ(val->left);
         if (val->right != NULL)
            EnQ(val->right);

/*
         printf("Q: ");
         PrintQ();
         printf("\n");
*/
//         getchar();
      }
   }
}

int main(int argc, char *argv[]) {
   BNode* root = NULL;   
   BNode* tmp = NULL;

   int data[] = {  5, 3, 1, 4, 7, 6, 8 };
   int n = sizeof(data)/sizeof(int);

   for (int i=0; i<n; i++) {
      tmp = (BNode*)malloc(sizeof(BNode));
      if (tmp != NULL) {
         tmp->data = data[i];
         tmp->left = NULL;
         tmp->right = NULL;
         InsertBinTree(&root, tmp);
      } else {
         printf("Error: malloc for BNode failed!\n");
         exit(-1);
      }
   }

   printf("Binary Tree - DFS:\n");
   DFSBinTree(root);
   printf("\n");

   printf("Binary Tree - BFS:\n");
   BFSBinTree(root);
   printf("\n");
   return 0;
}
