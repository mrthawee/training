#include <iostream>

using namespace std;

class Node {
   friend class List;
   private:
      int   value;
      Node *next;
   public:
      Node() : next(NULL) { }
      Node(int v) : value(v), next(NULL) { }
      Node(int v, Node* n) : value(v), next(n) { }

      int getValue(void) { return value; }
      Node* getNext(void) { return next; }
};

class List{
   private:
      Node *head;
      Node *tail;

      void recursivelyReverseList(Node **head);
      void rr2(Node *prev, Node *curr);
      void dump(Node *c);

   public:
//      List(void) : head(NULL), tail(NULL) { }
      List() : head(NULL) { }
      List(int v);
      ~List(void);

      void Print();
      void Add(int v);  // add to tail
      void Remove(int v);
      void Reverse(void);
      void ReverseRecursive(void);
      int  Length();
      int  Count(int v);
      int  GetNth(int v);
      void DeleteList();
      void Push(int v);  // add to head;
      int  Pop();        // delete the 1st node from head
      void InsertNth(int idx, int v);
};

List::List(int v) {
   head = new Node(v);
//   tail = head;
}

List::~List(void) {
//   if (head == NULL)
//      return;

   Node *curr = NULL;
   while (head != NULL) {
      curr = head->next;
      delete head;
      head = curr;
   }

//   tail = NULL; 
}

void List::Add(int v) {
   Node *n = new Node(v);
   
   if (head == NULL) {
      head = n;
   } else {
      Node *curr = head;
      while (curr->next != NULL)
         curr = curr->next;
      curr->next = n;
   }
/*
   tail->next = n;
   tail = tail->next;
*/
}

void List::Remove(int v) {
   Node *curr = head;

   if (head->value == v) {
      head = head->next;
      delete curr;
   } else {
      Node *prev = head;
      while (prev->next->value != v) {
         prev = prev->next;
      }
      curr = prev->next;
      prev->next = prev->next->next;
      delete curr;
   }
}

void List::Reverse(void) {
   if (head == NULL)
      return;

   Node *prev = NULL;
   Node *curr = NULL;

   while (head->next != NULL) {
      curr = head;
      head = head->next;
      curr->next = prev;
      prev = curr;
   }
   head->next = prev; // connect the last node back to the rest 
}

void List::ReverseRecursive(void) {
//   recursivelyReverseList(&head);
   rr2(NULL, head);
}

void List::recursivelyReverseList(Node **head) {
   if (head == NULL)
      return;
   
   Node *curr = *head;
   Node *rest = curr->next;

   if (rest == NULL)
      return;

   recursivelyReverseList(&rest);
   curr->next->next = curr;  // put the first node on the end of the list
   curr->next = NULL; // tricky step -- make a drawing

   *head = rest;
}

void List::rr2(Node *prev, Node *curr) {
   if (curr) {
      rr2(curr, curr->next);
      curr->next = prev;
   } else {
      head = prev;
   }
}

void List::Print() {
   Node *curr = head;

   while (curr != NULL) {
      cout << curr->value << " ";
      curr = curr->next;
   }

   cout << endl;
}

void List::dump(Node *c) {
   cout << "dump: ";
   while (c != NULL) {
      cout << c->value << " ";
      c = c->next;
   }
   cout << endl;
}

int List::Length() {
   int count = 0;
   Node *c = head;

   while (c != NULL) {
      c = c->next;
      count++;
   }

   return count;
}

int List::Count(int v) {
   int count = 0;
   Node *c = head;

   while (c != NULL) {
      if (c->value == v) {
         count++;
      }
      c = c->next;
   }

   return count;
}

int List::GetNth(int n) {
   int cnt = 0;
   Node *curr = head;
   for (int cnt=0; cnt<=n; cnt++) {
//      cout << "n=" << n << "  cnt=" << cnt << endl;
      if (curr != NULL) {
//         cout << " curr->value= " << curr->value << endl;
         curr = curr->next;
      } else {
         cout << "End of list @ index = " << cnt << endl;
         return -1;
      }
   }

   return curr->value;
}

void List::DeleteList() {
   Node *curr = head;

   while (curr != NULL) {
      head = curr->next;
      delete curr;
      curr = head;
  }
}

void List::Push(int v) {
   Node *n = new Node(v);

   n->next = head;
   head = n;
}

int List::Pop() {
   int v = -1;
   if (head != NULL) {
      Node *c = head;
      head = head->next;
      v = c->value;
      delete c;
   }

   return v;
}

void List::InsertNth(int idx, int v) {

   if (idx <= 0) {
      Push(v);
   } else {
      Node *n = new Node(v);
      Node *prev = head;
      // looping to Node idx-1
      for (int i=0; i<idx-1; i++) {
         if (prev != NULL) {
            prev = prev->next;
         } else {
            cout << "Error in InsertNth() : End of list @ idx = " << i << endl;
            return;
         }
      }

      cout << "Insert @ prev->value = " << prev->value << endl;
//      if (prev != NULL) {
         n->next = prev->next;
         prev->next = n;
/*
      } else {
         cout << "Error in InsertNth() : NULL before idx=" << idx << endl;
         return;
      }
*/
   }
}
   

int main(void) {
   List l1(30);
   
   cout << "List l1(30): ";
   l1.Print();

   cout << "Add(20): ";
   l1.Add(20);
   l1.Print();
   cout << "Add(10): ";
   l1.Add(10);
   l1.Print();
   cout << "Add(40): ";
   l1.Add(40);
   l1.Print();
   cout << "Add(100): ";
   l1.Add(100);
   l1.Print();
   cout << "Add(10): ";
   l1.Add(10);
   l1.Print();
   
   cout << "Remove(30): ";
   l1.Remove(30);
   l1.Print();

   cout << "Remove(40): ";
   l1.Remove(40);
   l1.Print();

   cout << "Reverse(): ";
   l1.Reverse();
   l1.Print();

   cout << "Remove(20): ";
   l1.Remove(20);
   l1.Print();

   cout << "#Nodes with 10 = " << l1.Count(10) << endl;
   cout << "GetNth with 1 = " << l1.GetNth(1) << endl;

   cout << "Push(5) : ";
   l1.Push(5);
   l1.Print();
   cout << "Pop = " << l1.Pop() << endl;

   cout << "InsertNth(2, 3): ";
   l1.InsertNth(2, 3);
   l1.Print();
   cout << "InsertNth(0, 99): ";
   l1.InsertNth(0, 99);
   l1.Print();

   cout << "InsertNth(5, 111): ";
   l1.InsertNth(5, 111);
   l1.Print();

   cout << "RecursiveReverse(): ";
   l1.ReverseRecursive();
   l1.Print();

   cout << "DeleteList(): ";
   l1.DeleteList();
   l1.Print();
   return 0;
}
