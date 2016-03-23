#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
   int          data;
   struct node *next;
};

/*
 * Function Declaration
 *
 */
int Length(struct node *curr);
void Push(struct node **headRef, int data);
void Print(struct node *curr);
void Free(struct node **headRef);

struct node* BuildOneTwoThree();
void BasicsCaller();

/*
 * Function Definitions
 */
int Length(struct node *curr) {
   int count = 0;
   while (curr) {
      count++;
      curr = curr->next;
   }
   return count;
}

void Push(struct node **headRef, int data) {
   struct node *head = *headRef;
   struct node *newNode = (struct node*)malloc(sizeof(struct node));

   assert(newNode != NULL);

   newNode->data = data;
   newNode->next = head;
   head = newNode;

   *headRef = head;
}
   
void Print(struct node *curr) {
   while (curr) {
      printf("%d ", curr->data);
      curr = curr->next;
   }
   printf("\n");
}

void Free(struct node **headRef) {
   struct node *head = *headRef;
   struct node *curr = head;

   while (curr) {
      head = head->next;
      free(curr);
      curr = head;
   }

   *headRef = head;
}

struct node* BuildOneTwoThree() {
   struct node *list = NULL;
/*
   struct node *list = (struct node*)malloc(sizeof(struct node));
   list->data = 3;
   list->next = NULL;
*/
   int i;
   for (i=3; i>0; i--)
      Push(&list, i);

   return list;
/*
   struct node *one = (struct node*)malloc(sizeof(struct node));
   assert(one != NULL);
   struct node *two = (struct node*)malloc(sizeof(struct node));
   assert(two != NULL);
   struct node *tri = (struct node*)malloc(sizeof(struct node));
   assert(tri != NULL);

   one->data = 1;
   one->next = two;

   two->data = 2;
   two->next = tri;

   tri->data = 3;
   tri->next = NULL;

   return one;
*/
}

void BasicsCaller() {
   struct node* head;
   int len;
   head = BuildOneTwoThree();

   Push(&head, 13);
   Push(&(head->next), 42);

   Print(head);
   printf("len = %d\n", Length(head));

   Free(&head);

   if (head == NULL)
      printf("Now head is NULL!\n");
   else
      printf("Nope! head is not NULL yet!\n");
}


int GetNth(struct node* head, int index) {
   int i=0;
   while (head != NULL) {
      if (i == index)
         return head->data;
      head = head->next;
      i++;
   }

   return -100000;
}

int InsertNth(struct node **headRef, int index, int data) {
   struct node *head = *headRef;
   struct node *curr = head;
   struct node *newNode = (struct node*)malloc(sizeof(struct node));

   assert(newNode != NULL);

   newNode->data = data;
   newNode->next = NULL;

   int i=0;
   int gotInserted = 0;
   if (index == 0) {
      if (head == NULL) {
         head = newNode;
      } else {
         newNode->next = head;
         head = newNode;
      }
      gotInserted = 1;
   } else {
      while (curr != NULL) {
         if (i == index-1) {
            newNode->next = curr->next;
            curr->next = newNode;
            gotInserted = 1;
            break;
         }
         i++;
         curr = curr->next;
      }
   }

   if (gotInserted == 0) {
      free(newNode);
   }

   *headRef = head;
}

/*
 * Insert a node into a sorted list
 * - need to find where to be inserted to keep the list sorted
 */
void SortedInsert(struct node **headRef, struct node *newNode) {
   struct node *head = *headRef;
   struct node *curr = head;

   if (head == NULL) {
      head = newNode;
   } else if (newNode->data <= head->data) {
      newNode->next = head;
      head = newNode;
   } else {
      while ((curr->next != NULL)&& (newNode->data > curr->next->data)) {
//      while (newNode->data > curr->next->data) {
//    **** Need to check if curr->next != NULL ***
//    **** Otherwise, you can't insert the 2nd node ***
         curr = curr->next;
      }
      newNode->next = curr->next;
      curr->next = newNode;
   }

   *headRef = head;
}

/* 
 * Giving an unsorted list, make it sorted.
 */
void InsertSort(struct node **headRef) {
   struct node *head = *headRef;
   struct node *curr = head;
   struct node *sList = NULL;
   struct node *next = NULL;

   while (curr) {
      next = curr->next;
      curr->next = NULL;
      SortedInsert(&sList, curr);
      curr = next;
   }

   *headRef = sList;
}

void Append(struct node **aRef, struct node **bRef) {
   struct node *a = *aRef;
   struct node *curr = a;
   struct node *b = *bRef;

   if (a == NULL) {
      a = b;
   } else {
      while (curr->next != NULL) {
         curr = curr->next;
      }

      curr->next = b;
   }

   *aRef = a;
   *bRef = NULL;
}

void FrontBackSplit(struct node* source, struct node **frontRef, struct node **backRef) {

   struct node *curr = source;
   int len = Length(source);
   int half = len/2;

   if (len == 1) {
      *frontRef = source;
      *backRef = NULL;
   } else {
      
      int count = 0;
      for(; count <half; count++)
         curr = curr->next;

      *frontRef = source;
      *backRef = curr->next;

      curr->next = NULL;
   }
}

/*
 * Write a RemoveDuplicate() function which takes a list sorted in 
 * increasing order and deletes any duplicate nodes from the list. Ideally,
 * the list should only be traversed once.
 */
void RemoveDuplicates(struct node *head) {
   while ( (head != NULL)
            && (head->next != NULL) ) {
      if (head->data != head->next->data) {
         head = head->next;
      } else {
         struct node *tmp = head->next;
         head->next = head->next->next;
         free(tmp);
      }
   }
/*
   struct node *curr = head;
   if (curr == NULL)
      return;

   while (curr->next != NULL) {
      if (curr->data == curr->next->data) {
         struct node *nextNode = curr->next->next;
         free(curr->next);
         curr->next = nextNode;
      } else {
         curr = curr->next;
      }
   }
*/
}

/*
 * MoveNode()
 * This is a variant on Push().  Instead of creating a new node and pushing 
 * it onto the given list, MoveNode() takes two lists, removes the front node
 * from the second list and pushes it onto the front of the first. This turns
 * out to be a handy utility function to have for several later problems.
 * Both Push() and MoveNode() are designed around the feature that list 
 * operations work most naturally at the head of the list.  Here's a simple
 * example of what MoveNode() should do.
 *
 * a = { 1, 2, 3 }
 * b = { 1, 2, 3 }
 *
 * MoveNode(&a, &b);
 * a = { 1, 1, 2, 3 }
 * b = { 2, 3 }
 *
 */
void MoveNode(struct node** destRef, struct node **sourceRef) {
   struct node *src = *sourceRef;
   struct node *dst = *destRef;
   if (src != NULL) {
      struct node *tmp = src;
      src = src->next;
      tmp->next = dst;
      dst = tmp;

      *sourceRef = src;
      *destRef = dst;
   }
      
/*
   if (*sourceRef != NULL) {
      struct node *movingNode = *sourceRef
      *sourceRef = movingNode->next; 
      movingNode->next = *destRef;
      *destRef = movingNode;
   }
*/
}

/*
 * AlternativeSplit()
 * Write a function AlternativeSplit() that takes one list and divides up its
 * nodes to make two smaller lists. The sublists should be made fro alternating
 * elements in the original list.  So if the original list is { a,b,a,b,a,b },
 * then one sublist should be { a,a,a } and the other should be { b,b,b }.
 *
 */
void AlternativeSplit(struct node *source, struct node **aRef, struct node **bRef) {
   struct node *aHead = *aRef;
   struct node *bHead = *bRef;

   struct node *aCurr = aHead;
   struct node *bCurr = bHead;

   int i=0;
   while (source != NULL) {
      struct node *curr = source;
      if ( i % 2 == 0 ) {
         if (aHead == NULL) {
            aHead = curr;
            source = source->next;
            aCurr = aHead;
         } else {
            aCurr->next = curr;
            source = source->next;
            aCurr = aCurr->next;
         }
         aCurr->next = NULL;
      } else {
         if (bHead == NULL) {
            bHead = curr;
            source = source->next;
            bCurr = bHead;
         } else {
            bCurr->next = curr;
            source = source->next;
            bCurr = bCurr->next;
         }
         bCurr->next = NULL;
      }
      i++;
   }

   *aRef = aHead;
   *bRef = bHead;
} 

/*
 * ShuffleMerge()
 * Given two lists, merge their nodes together to make one list, taking
 * noded alternatively between the two lists.  So ShuffleMerge() with 
 * { 1,2,3 } and {7,13,1} should yeild {1,7,2,13,3,1}. If either list runs
 * out, all the nodes should be taken from the other list.
 */
struct node* ShuffleMerge(struct node* a, struct node* b) {

   struct node *mHead = NULL;
   struct node *mCurr = NULL; 
   
   if (a == NULL) {
      return b;
   } else if (b == NULL) {
      return a;
   } else { 
      mHead = a;
      mCurr = mHead;
      a = a->next;
      mCurr->next = NULL;

      while (a != NULL && b != NULL) {
         if (b != NULL) {
            mCurr->next = b;
            b = b->next;
            mCurr = mCurr->next;
            mCurr->next = NULL;
         } 

         if (a != NULL) {
            mCurr->next = a;
            a = a->next;
            mCurr = mCurr->next;
            mCurr->next = NULL;
         }
      }

      if (a == NULL) {
         mCurr->next = b;
      }

      if (b == NULL) {
         mCurr->next = a;
      }

      return mHead;
   }
}

/*
 * SortedMerge()
 * Write a SortedMerge() function that takes two lists, each of which is 
 * sorted in increasing order, and merges the two together into one list
 * which is in increasing order. SortedMerge() should return the new list.
 * Ideally, Merge() should only make one pass through each list.
 *
 */
struct node* SortedMerge(struct node *a, struct node *b) {

   if (a == NULL)
      return b;
   else if (b == NULL)
      return a;
   else {
      struct node *mHead = NULL;
      struct node *mCurr = NULL;

      if (a->data <= b->data) {
         mHead = a;
         a = a->next;
      } else {
         mHead = b;
         b = b->next;
      }

      mCurr = mHead;

      while (a != NULL && b != NULL) {
         if (a->data <= b->data) {
            mCurr->next = a;
            a = a->next;
         } else {
            mCurr->next = b;
            b = b->next;
         }
         mCurr = mCurr->next;
      }

      if (a == NULL) {
         mCurr->next = b;
      } else if (b == NULL) {
         mCurr->next = a;
      }

      return mHead;
   }
}

struct node* BuildList(int arr[], int len) {
   struct node *head = NULL;
   struct node *curr = NULL;
   struct node *tmp = NULL;
   int i;
   for (i=0; i<len; i++) {
      tmp = (struct node*)malloc(sizeof(struct node));
      tmp->data = arr[i];
      tmp->next = NULL;
      if (head == NULL) {
         head = tmp;
         curr = head;
      } else {
         curr->next = tmp;
         curr = curr->next; 
      }
   } 

   return head;
}

int main() {
   printf("BuildOneTwoThree:\n");
   struct node *list = BuildOneTwoThree();
   Print(list);
   printf("BuildOneTwoThree - End\n");

   /* Test GetNth */
   printf("GetNth:\n");
   int i;
   for (i=0; i<5; i++) {
      int d = GetNth(list, i);
      printf("index = %d, d = %d\n", i, d);
   }
   Free(&list);
   printf("GetNth - End\n");

   /* Test InsertNth */
   printf("InsertNth:\n");
   InsertNth(&list, 0, 13);  /* { 13 } */
   InsertNth(&list, 1, 42);  /* { 13, 42 } */
   InsertNth(&list, 1, 5);   /* { 13, 5, 42 } */
   InsertNth(&list, 2, 45);  /* { 13, 5, 45, 42 } */
   InsertNth(&list, 4, 77);  /* { 13, 5, 45, 42, 77 } */
   InsertNth(&list, 10, 99); /* { 13, 5, 45, 42, 77 } : no insertion */
   Print(list);
   Free(&list);
   printf("InsertNth - End\n");

   /* Test SortedInsert */
   printf("SortedInsert:\n");
   struct node *n1 = (struct node*)malloc(sizeof(struct node));
   assert(n1 != NULL);
   n1->data = 3;
   n1->next = NULL;
   SortedInsert(&list, n1); /* { 3 } */

   struct node *n2 = (struct node*)malloc(sizeof(struct node));
   assert(n2 != NULL);
   n2->data = 33;
   n2->next = NULL;
   SortedInsert(&list, n2);  /* { 3, 33 } */

   struct node *n3= (struct node*)malloc(sizeof(struct node));
   assert(n3 != NULL);
   n3->data = 23;
   n3->next = NULL;
   SortedInsert(&list, n3);  /* { 3, 23, 33 } */

   Print(list);
   Free(&list);
   printf("SortedInsert - End\n");

   /* Test InsertSort */
   printf("InsertSort:\n");
   InsertNth(&list, 0, 13);  /* { 13 } */
   InsertNth(&list, 1, 42);  /* { 13, 42 } */
   InsertNth(&list, 1, 5);   /* { 13, 5, 42 } */
   InsertNth(&list, 2, 45);  /* { 13, 5, 45, 42 } */
   InsertNth(&list, 4, 77);  /* { 13, 5, 45, 42, 77 } */
   Print(list);

   InsertSort(&list);
   Print(list);
   Free(&list);
   printf("InsertSort - End\n");

   /* Test Append(**aRef, **bRef) */
   printf("Append:\n");
   struct node *a = BuildOneTwoThree();
   struct node *b = BuildOneTwoThree();
   Append(&a, &b);
   Print(a);
   Print(b);
   Free(&a);
   Free(&b);
   printf("Append - End\n");

   /* Test FrontBackSplit */
   printf("FrontBackSplit:\n");
   struct node *src = BuildOneTwoThree();
   printf("Source: ");
   Print(src);
   struct node *front = NULL;
   struct node *back = NULL;
   FrontBackSplit(src, &front, &back);
   printf("Front: ");
   Print(front);
   printf("Back: ");
   Print(back);

// You can't Free(&src) because it will be freed by Free(&front)
// Otherwise, it will be double free -> exception
//   Free(&src);
   Free(&front);
   Free(&back);
   printf("FrontBackSplit - End\n");

   /* Test RemoveDuplicates() */
   printf("RemoveDuplicates:\n");
   struct node *rmX = BuildOneTwoThree();
   Push(&rmX, 1);
   InsertNth(&rmX, 2, 2); 
   InsertNth(&rmX, 5, 3); 
   printf("Ready: ");
   Print(rmX);
   printf("After RemoveDuplicates(): ");
   RemoveDuplicates(rmX);
   Print(rmX);
   Free(&rmX);
   printf("RemoveDuplicates - End\n");

   /* Test MoveNode() */
   printf("MoveNode:\n");
   struct node *aSrc = BuildOneTwoThree();
   struct node *bSrc = BuildOneTwoThree();
   MoveNode(&aSrc, &bSrc);
   Print(aSrc);
   Print(bSrc);
   Free(&aSrc);
   Free(&bSrc);
   printf("MoveNode - End\n");

   /* Test AlternativeSplit() */
   printf("AlternativeSplit:\n");
   struct node *alt = BuildOneTwoThree();
   struct node *aAlt = NULL; 
   struct node *bAlt = NULL; 
   InsertNth(&alt, 0, 0);
   InsertNth(&alt, 4, 4);
   InsertNth(&alt, 5, 5);
   InsertNth(&alt, 6, 6);
   printf("Before: \n alt:");
   Print(alt);
   AlternativeSplit(alt, &aAlt, &bAlt);
   printf("After: \n alt:");
   Print(alt);
   printf("a: ");
   Print(aAlt);
   printf("b: ");
   Print(bAlt);
// You can't Free(&src) because it will be freed by Free(&front)
// Otherwise, it will be double free -> exception
//   Free(&src);
   Free(&aAlt);
   Free(&bAlt);
   printf("AlternativeSplit - End\n");

   /* Test ShuffleMerge() */
   printf("ShuffleMerge:\n");
   struct node *aSh = BuildOneTwoThree();
   struct node *bSh = BuildOneTwoThree();
   printf("aSh: ");
   Print(aSh);
   printf("bSh: ");

   Print(bSh);
   struct node *mSh = ShuffleMerge(aSh, bSh);
   printf("aSh: ");
   Print(aSh);
   printf("bSh: ");
   Print(bSh);
   printf("mSh: ");
   Print(mSh);
   Free(&mSh); 
   printf("ShuffleMerge - End\n");

   /* Test SortedMerge() */
   printf("SortedMerge:\n");
   int arr1[] = { 2, 4, 6 };
   struct node *aSrt = BuildList(arr1, 3);
   int arr2[] = { 1, 3, 5 };
   struct node *bSrt = BuildList(arr2, 3);
   Print(aSrt);
   Print(bSrt);
   struct node *m = SortedMerge(aSrt, bSrt);
   Print(m);
   Print(aSrt);
   Print(bSrt);
   Free(&m);
   printf("SortedMerge - End\n");
}
