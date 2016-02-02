#include <iostream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

class List {
   private:

   public:
      List *head; // pointer to start of list
      List *tail; // pointer to end of list
      List *next; // pointer to the next item
      int   data;;  // value to be stored
      List() { head = tail = next = NULL; }
      virtual ~List();
      virtual void store(int i) = 0;
      virtual int  retrieve() = 0;
};

// Thawee's implementation : to prevent any memory leak
List::~List() {
//   cout << "in ~List()\n";

   int n = 0;
   List *p;
   while (head) {
      p = head;
      head = head->next;
//      cout << n << " Delete List->data = " << p->data << endl;
//      n++;
      delete p;
   }
//   cout << "Delete " << n << " items\n";
      
   head = tail = next = NULL;
}

class Queue : public List {
   private:

   public:
      void store(int i);  // to be implemented here
      int  retrieve();    // to be implemented here
};

void Queue::store(int i) {
   List *item;

   item = new Queue;
   if (!item) {
      cout << "Error: Can't create new Queue item!\n";
      exit (1);
   }

   item->data = i;

   // put on the end of list : nature of Queue
   if (tail)
       tail->next = item;
   tail = item;
   item->next = NULL;
   if (!head) 
      head = tail;
}

int Queue::retrieve() {
   int   i;
   List *p;

   if (!head) {
      cout << "Queue is empty: nothing to be retrieved.\n";
      return -1;
   }

   // remove from the start of list
   i = head->data;
   p = head;
   head = head->next;

   delete p;

   return i;
}

class Stack : public List {
   private:

   public:
      void store(int i);  // to be implemented here
      int  retrieve();    // to be implemented here
};

void Stack::store(int i) {
   List *item;

   item = new Stack;
   if (!item) { // if (item == NULL)
      cout << "Error: Can't create new Stack item!\n";
      exit(1);
   }

   item->data = i;

   // put on the front of List : nature of Stack
   if (head)  // if (head != NULL)
      item->next = head;
   head = item;
   if (!tail) // if (tail == NULL)
      tail = head;
}
      
int Stack::retrieve() {
   int  i;
   List *p;

   if (!head) {
      cout << "Stack is empty: nothing to be retrieved.\n";
      return -1;
   }

   // remove from the front of List : nature of Stack
   i = head->data;
   p = head;
   head = head->next;
   delete p;

   return i;
}

int main() {
   List *p;

   Queue qObj;
   p = &qObj;
   p->store(1);
   p->store(2);
   p->store(3);

   cout << "Queue: ";
   cout << p-> retrieve() << " ";
   cout << p-> retrieve() << " ";
   cout << p-> retrieve() << " ";
   cout << endl;

   Stack sObj;
   p = &sObj;
   p->store(1);
   p->store(2);
   p->store(3);

   cout << "Stack: ";
   cout << p-> retrieve() << " ";
   cout << p-> retrieve() << " ";
   cout << p-> retrieve() << " ";
   cout << endl;
   
   return 0;
}
