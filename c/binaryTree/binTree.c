#include <stdio.h>
#include <stdlib.h>

struct node {
   int          data;
   struct node* left;
   struct node* right;
};

struct node* NewNode(int data) {
   struct node *n = (struct node*)malloc(sizeof(struct node));

   n->data = data;
   n->left = NULL;
   n->right = NULL;

   return n;
}

struct node* Insert(struct node *root, int data)  {
   if (root == NULL) {
      return NewNode(data);
   } else {
      if (data <= root->data) {
         root->left = Insert(root->left, data);
      } else { // data > root->data
         root->right = Insert(root->right, data);
      }

      return root;
   }
}

struct node* Build123() {
   struct node *root = NULL;
   root = Insert(root, 2);
   root = Insert(root, 1);
   root = Insert(root, 3);

   return root;
}

int Size(struct node* root) {
   if (root == NULL) {
      return 0;
   } else {
      return (Size(root->left) + 1 + Size(root->right));
   }
}

int MaxDepth(struct node *root) {
   if (root == NULL) {
      return 0;
   } else {
      int lDepth = MaxDepth(root->left);
      int rDepth = MaxDepth(root->right);

      if (lDepth > rDepth)
         return lDepth + 1;
      else
         return rDepth + 1;
   }
}

int MinValue(struct node* root) {
   if (root == NULL) {
      return -10000;
   } else {
      while (root->left != NULL) {
         root = root->left;
      }

      return root->data;
   }
}

void PrintTree(struct node *root) {
   if (root == NULL) {
      return;
   } else {
      PrintTree(root->left);
      printf("%d ", root->data);
      PrintTree(root->right);
   }
}

// give a sum - find if sum data of path to leaf equals to the given sum
int HasPathSum(struc node* root, int sum) {

}
   
int main(void) {
   struct node *root = NULL;

   root = Build123();
   printf("MaxDepth(root) = %d\n", MaxDepth(root));
   printf("MinValue(root) = %d\n", MinValue(root));
   printf("Size(root) = %d\n", Size(root));
   PrintTree(root);
   printf("\n");

   return 0;
}
