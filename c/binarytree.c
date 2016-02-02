#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
   struct NodeType* left;
   struct NodeType* right;
   int   data;
}Node;

void InsertBinaryTree(Node** top, Node* new) {
   if ((*top) != NULL) {
      printf("currTop->data = %d : new->data = %d\n", (*top)->data, new->data);
   } else {
      printf("currTop = NULL : new->data = %d\n",  new->data);
   }
   if ((*top) == NULL) {
      *top = new;
      //top->left = NULL;
      //top->right = NULL;
   } else if ((*top)->data > new->data) { // insert to the left
      printf("go left, ");
      InsertBinaryTree(&(*top)->left, new);
   } else if ((*top)->data <= new->data) {
      printf("go right, ");
      InsertBinaryTree(&(*top)->right, new);
   }
}

void PrintBinaryTreeInfix(Node *top) {
   if (top != NULL) {
      if (top->left != NULL) {
         PrintBinaryTreeInfix(top->left);
      }
      printf(" %d ", top->data);

      if (top->right != NULL) {
            PrintBinaryTreeInfix(top->right);
      }
   }
}

void PrintBinaryTreePrefix(Node *top) {
   if (top != NULL) {

      printf(" %d ", top->data);

      if (top->left != NULL) {
         PrintBinaryTreePrefix(top->left);
      }

      if (top->right != NULL) {
            PrintBinaryTreePrefix(top->right);
      }
   }
}

void PrintBinaryTreePostfix(Node *top) {
   if (top != NULL) {
      if (top->left != NULL) {
         PrintBinaryTreePrefix(top->left);
      }

      if (top->right != NULL) {
            PrintBinaryTreePrefix(top->right);
      }

      printf(" %d ", top->data);
   }
}

int main() {
   Node* root = NULL;
   Node* tmp = NULL;
   
   int dummy[] = { 6, 9, 7, 3, 1, 4, 5, 2 };

   int nDummies = 8;

   for (int i=0; i<nDummies; i++) {
      tmp = (Node*)malloc(sizeof(Node));
      if (tmp != NULL) {
         tmp->data = dummy[i];
//         printf("tmp->data = %d\n", tmp->data);
         tmp->left = NULL;
         tmp->right = NULL;
         InsertBinaryTree(&root, tmp);
      } else {
         printf("Error: out of memory!\n");
         exit (-1);
      }
   }

   printf("Print Binary Tree - Prefix:");
   PrintBinaryTreePrefix(root);
   printf("\n");

   printf("Print Binary Tree - Infix:");
   PrintBinaryTreeInfix(root);
   printf("\n");

   printf("Print Binary Tree - Postfix:");
   PrintBinaryTreePostfix(root);
   printf("\n");
}
