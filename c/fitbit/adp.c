/*****************************************************************************
 * Accelerometer Data Processing: ADP
 *
 * by Thawee Techathamnukool
 * on 03/02/2016
 *
 * History:
 *  v. 1.0.0 : Initial version 
 *
 * Input: 
 *  - Binary file with unsigned 12-bit samples
 *
 * Output:
 *  - Text file with the list of last 32 sample values and 32 largest sample
 *    value
 *
 * How to run:
 *     Usage: ./adp <input file name> <output file name>
 * Ex: ./adp test1.bin test1.out
 *
 * Design Decision and Tradeoffs:
 * Data Structure: 
 * 1. Singly Linked List with Head and Tail pointers for sequential input
 *    list and sorted input list.
 *    Tradeoffs: 
 *      - Static array is not a good choice because we need to insert 
 *        and delete data.  We will be too busy handling array indices.
 *      - Doubly linked list could be an alternative.  Since we don't 
 *        need "delete tail" operation, Singly linked list is good enough
 *        to handle "add tail" operation. Also, Doubly linked list will
 *        need more code to handle more pointers which could be error prones.
 *        And each node and Double linked list needs another pointer to 
 *        previous node, which will end up with more memory need to run
 *        that.
 * 2. Singly Linked List to recycle "deleted" node.  Rather than calling
 *    free() and malloc() directly.  This code has RecycleList to keep
 *    track of all available to be reused node.
 *    Tradeoffs:
 *     - Calling malloc() and free() is slower.
 *     - Calling malloc() and free() frequently may result in memory 
 *       fragmentation in Heap.
 *
 * Optimizations:
 * 1. Memory optimization with 'recycleList' : to keep deleted node for reuse
 *     - When needing a new node, CreateNode() is called to check with
 *       the recycle list first and retrieve one if there is any.
 *     - This should minimize the malloc and free operations which are
 *       slow and potentially fragmenting the Heap.
 * 2. Speed Optimization with head and tail pointers to each sample list.
 *     - for sequential list, this code can like a queue effectively
 *       by adding new node to the tail without traversing and deleting
 *       oldest node from the front.
 *     - for sorted list, new min/max can be added without traversing
 *         - if new value <= min (front node), add front
 *         - if new value >= max (back node), add back
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*
 * define maximum number of inputs in the sequential and sorted lists 
 * NOTE: this value must be at least 1
 */
#define MAX_NUM_NODES 32

/*
 * typedef for data types
 */
typedef unsigned char   uint8;
typedef unsigned short  uint16;

/* 
 * NodeType : definition of the singly linked list node
 */
typedef struct node {
   uint16       data;
   struct node *next;
} NodeType;

/*****************************************************************************
 * Global Data Definitions:
 ****************************************************************************/
/* 
 * SeqList : list of input stored sequentially (add back)
 *  - seqListHead : point to the head of sequentail list
 *  - seqListTail : point to the tail of sequentail list
 *  - seqListCnt  : count number of nodes in sequentail list
 */
NodeType *seqListHead = NULL;
NodeType *seqListTail = NULL;
uint8     seqListCnt = 0;


/* 
 * sortedList : list of sorted input list
 *  - sortedListHead : point to the head of sorted list
 *  - sortedListTail : point to the tail of sorted list
 *  - sortedListCnt  : count number of nodes in sorted list
 */
NodeType *sortedListHead = NULL;
NodeType *sortedListTail = NULL;
uint8     sortedListCnt = 0;

/*
 * recycleList : list of available node to be reused
 *  - add front when put into this list
 *  - delete front when taken away
 */
NodeType *recycleList = NULL;

/*****************************************************************************
 * Function Declarations:
 ****************************************************************************/

/* Create and Delete : comparable to malloc() and free() */
NodeType *CreateNode(uint16 val); 
void DeleteNode(NodeType *node);

/* Insert a node to and delete a node from a list */
void InsertFront(NodeType **headRef, NodeType **tailRef, uint16 val);
void InsertBack(NodeType **headRef, NodeType **tailRef, uint16 val);
void InsertSort(NodeType **headRef, NodeType **tailRef, uint16 val);
void DeleteFront(NodeType **headRef, NodeType **tailRef);

/* Insert new node with specific 'val' to the specific list */
void InsertSeqList(uint16 val);
void InsertSortedList(uint16 val);

/* Read file and process samples */
void ReadAndProcessSamples(FILE *ifp);

/* Write data of a list to file */
void WriteList(FILE *ofp, NodeType *curr);

/* Wrapper functions to write specific list to file */
void WriteSortedList(FILE *ofp);
void WriteSeqList(FILE *ofp);

/* Utility function to empty a list and return all node to recycle list */
void DisposeList(NodeType **headRef, NodeType **tailRef);

/* Utility function to really free all memory back to Heap */
void FreeAllMemory();

/*****************************************************************************
 * Function Definitions:
 ****************************************************************************/
/*
 * CreateNode(val): malloc() only when new node needs to be allocated
 *  - if recycle node is available, take one from recycleList
 *  - otherwise, allocate one from the heap
 *
 *  Argument: 
 *     val : new node wiill be created with its data set to this value
 *
 *  Return:
 *     NodeType * : pointer to new node with data = val
 *
 */
NodeType *CreateNode(uint16 val) {
   NodeType *newNode = NULL;

   if (recycleList != NULL) {
      newNode = recycleList;
      recycleList = recycleList->next; 
   } else {
      newNode = (NodeType *)malloc(sizeof(NodeType));
      assert(newNode != NULL);
   }
   
   newNode->data = val;
   newNode->next = NULL;

   return newNode;
}

/*
 * DeleteNode : put a linked list node into the recycle list
 *  - NULL node is ignored
 *
 *  Argument: 
 *     NodeType * : pointer to  node
 *
 *  Return:
 *     N/A
 */
void DeleteNode(NodeType *node) {
   if (node != NULL) {
      node->next = recycleList;
      recycleList = node;
   }
}

/*
 * InsertFront : add a new node to the front of list
 *
 *  Argument: 
 *     **headRef : pointer to pointer to head node of the list
 *     **tailRef : pointer to pointer to tail node of the list
 *     val : new node wiill be created with its data set to this value
 *
 *  Return:
 *     N/A
 *
 */
void InsertFront(NodeType **headRef, NodeType **tailRef, uint16 val) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;
   NodeType *newNode = CreateNode(val);

   if (head == NULL) {
      head = tail = newNode;
   } else {
      newNode->next = head;
      head = newNode;
   }

   *headRef = head;
   *tailRef = tail;
}

/*
 * InsertBack : add a new node to the back of list
 *
 *  Argument: 
 *     **headRef : pointer to pointer to head node of the list
 *     **tailRef : pointer to pointer to tail node of the list
 *     val : new node wiill be created with its data set to this value
 *
 *  Return:
 *     N/A
 *
 */
void InsertBack(NodeType **headRef, NodeType **tailRef, uint16 val) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;
   NodeType *newNode = CreateNode(val);

   if (head == NULL) {
      head = tail = newNode;
   } else {
      tail->next = newNode;
      tail = newNode;
   }

   *headRef = head;
   *tailRef = tail;
}

/* 
 * InsertSort : add a new node into sorted position of list
 *  - sorting is from low to high (front to back)
 *  - front is min
 *  - back is max
 *  - if new node <= min, add to front
 *  - if new node >= max, add to tail
 *  - otherwise, search for the right position to be inserted
 *
 *  Argument: 
 *     **headRef : pointer to pointer to head node of the list
 *     **tailRef : pointer to pointer to tail node of the list
 *     val : new node wiill be created with its data set to this value
 *
 *  Return:
 *     N/A
 *
 */
void InsertSort(NodeType **headRef, NodeType **tailRef, uint16 val) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;

   if (head == NULL) {
      NodeType *newNode = CreateNode(val);
      head = tail = newNode;
   } else if (head->data >= val) {
      InsertFront(&head, &tail, val);
   } else if (tail->data <= val) {
      InsertBack(&head, &tail, val);
   } else {
      NodeType *newNode = CreateNode(val);
      NodeType *curr = head;
      while ((curr->next != NULL) & (curr->next->data < val)) {
         curr = curr->next; 
      }
      newNode->next = curr->next;
      curr->next = newNode;
   }

   *headRef = head;
   *tailRef = tail;
}

/*
 * DeleteFront : delete the front node of list
 *  - if list is empty, do nothing
 *
 *  Argument: 
 *     **headRef : pointer to pointer to head node of the list
 *     **tailRef : pointer to pointer to tail node of the list
 *
 *  Return:
 *     N/A
 *
 */
void DeleteFront(NodeType **headRef, NodeType **tailRef) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;
   NodeType *curr = NULL;

   if (head == NULL)
      return;

   if (head == tail) {
      curr = head;
      DeleteNode(curr);
      head = tail = NULL;
   } else {
      curr = head; 
      head = head->next;
      DeleteNode(curr);
   }

   *headRef = head;
   *tailRef = tail;
}


/*
 * DispostList : utility function to recycle all node of list to 
 *               recycle List
 *
 *  Argument: 
 *     **headRef : pointer to pointer to head node of the list
 *     **tailRef : pointer to pointer to tail node of the list
 *
 *  Return:
 *     N/A
 *
 */
void DisposeList(NodeType **headRef, NodeType **tailRef) {
   NodeType *head = *headRef;
   NodeType *tail = *tailRef;
   NodeType *curr = head;

   while (head != NULL) {
      curr = head;
      head = head->next;
      DeleteNode(curr);
   }

   head = tail = NULL;

   *headRef = head;
   *tailRef = tail; 
}

/*
 * InsertSeqList(val): function to insert a new val to sequential list
 *
 *  Argument: 
 *     val : new node wiill be created with its data set to this value
 *
 *  Return:
 *     N/A
 *
 */
void InsertSeqList(uint16 val) {
   NodeType *head = seqListHead;
   NodeType *tail = seqListTail;

   InsertBack(&head, &tail, val);
   seqListCnt++;
   if (seqListCnt > MAX_NUM_NODES) {
      DeleteFront(&head, &tail);
      seqListCnt--;
   }

   seqListHead = head;
   seqListTail = tail;
}

/*
 * InsertSortedList(val): function to insert a new val to sorted list
 *
 *  Argument: 
 *     val : new node wiill be created with its data set to this value
 *
 *  Return:
 *     N/A
 *
 */
void InsertSortedList(uint16 val) {
   NodeType *head = sortedListHead;
   NodeType *tail = sortedListTail;

   InsertSort(&head, &tail, val);
   sortedListCnt++;
   if (sortedListCnt > MAX_NUM_NODES) {
      DeleteFront(&head, &tail);
      sortedListCnt--;
   }

   sortedListHead = head;
   sortedListTail = tail;
}

/*
 * Write data of a list to file 
 *
 *  Argument: 
 *     *ofp : FILE pointer to output file
 *     *curr : pointer to where to start traversing and write data to file
 *
 *  Return:
 *     N/A
 *
 */
void WriteList(FILE *ofp, NodeType *curr) {
   while (curr != NULL) {
      fprintf(ofp, "%d\r\n", curr->data);
      curr = curr->next;
   }
}

/*
 * Wrapper functions to write sorted list to file
 *
 *  Argument: 
 *     *ofp : FILE pointer to output file
 *
 *  Return:
 *     N/A
 *
 */
void WriteSortedList(FILE *ofp) {
   fprintf(ofp, "--Sorted Max %d Values--\r\n", sortedListCnt);
   WriteList(ofp, sortedListHead);
}

/*
 * Wrapper functions to write sequential list to file
 *
 *  Argument: 
 *     *ofp : FILE pointer to output file
 *
 *  Return:
 *     N/A
 *
 */
void WriteSeqList(FILE *ofp) {
   fprintf(ofp, "--Last %d Values--\r\n", seqListCnt);
   WriteList(ofp, seqListHead);
}

/*
 * FreeAllMemory() : utility function to free all memory to Heap
 *
 *  Argument: 
 *     N/A
 *
 *  Return:
 *     N/A
 *
 */
void FreeAllMemory() {
   DisposeList(&seqListHead, &seqListTail);
   DisposeList(&sortedListHead, &sortedListTail);

   NodeType *curr = NULL;
   while (recycleList != NULL) {
      curr = recycleList;
      recycleList = recycleList->next;
      free(curr);
   }
}

/*
 * Read file and process samples 
 *
 *  Argument: 
 *     *ifp : FILE pointer to input file
 *
 *  Return:
 *     N/A
 *
 */
void ReadAndProcessSamples(FILE *ifp) {
   /* byteRead : to hold each byte read from input file */
   uint8  byteRead = 0;

   /* byteArray[3] : to construct 12-bit input data below */
   uint8  byteArray[3] = {0};

   /* inputU12 : to hold each 12-bit input data */
   uint16 inputU12 = 0;

   /* byteReadCnt : to count number of bytes read from file which
                    is needed as offset to construct 12-bit input */
   uint16 byteReadCnt = 0;

   /* Read one byte at a time until no more byte to be read */
   while (fread(&byteRead, sizeof(uint8), 1, ifp)) {
       /*
        * We can construct 2 of 12-bit fields, from every 3 bytes read.
        * However, we should extract 12-bit field from every enough
        * number of bytes read from file.
        *
        * If waiting for 3 bytes at a time, we may miss one valid input
        * from 2 bytes read then EOF.
        */ 
      if (byteReadCnt % 3 == 0) {
         /* with only 1st byte, not enough to create valid input yet */
         byteArray[0] = byteRead;

      } else if (byteReadCnt % 3 == 1) {
         /* with 1st and 2nd bytes read, construct one 12-bit input */
         byteArray[1] = byteRead;
         inputU12 = ((unsigned short)(byteArray[0]<<4) 
                        | (byteArray[1]>>4)) & 0xFFF;
      
         /* insert new 12-bit input into both lists */
         InsertSeqList(inputU12);
         InsertSortedList(inputU12);

      } else if (byteReadCnt % 3 == 2) {
         /* with 2nd and 3rd bytes read, construct one 12-bit input */
         byteArray[2] = byteRead;
         inputU12 = ((unsigned short)(byteArray[1]<<8) 
                        | byteArray[2]) & 0xFFF;

         /* insert new 12-bit input into both lists */
         InsertSeqList(inputU12);
         InsertSortedList(inputU12);

      }

      /* increment byte count */
      byteReadCnt++;
   }
}
   
/*
 * main : entry function
 * required 2 command-line arguments: <input file name> and <output file name>
 * 
 */
int main(int argc, char *argv[]) {
   if (argc < 3) {
      printf("Usage: ./adp <input file name> <output file name>\n");
      return (EXIT_FAILURE);
   }
      
   /* open input file for reading */
   FILE *ifp;
   ifp = fopen(argv[1], "rb");
   if (!ifp) {
      printf("Error: can't open input file '%s'\n", argv[1]);
      return (EXIT_FAILURE);
   }

   /* open output file for writing */
   FILE *ofp;
   ofp = fopen(argv[2], "w");
   if (!ofp) {
      printf("Error: can't open output file '%s'\n", argv[2]);
      return (EXIT_FAILURE);
   }

   /* read sample from file and process */
   ReadAndProcessSamples(ifp);

   /* write output files */
   WriteSortedList(ofp);
   WriteSeqList(ofp);

   /* close both file pointers */
   fclose(ifp);
   fclose(ofp);

   /* free all memory allocations */
   FreeAllMemory();

   return (EXIT_SUCCESS);
}
