#include <iostream>

using namespace std;

template<typename T>
class List {
private:
   T  data;
   List *next;
public:
   List(T d);
   void Add(List *node) {
      node->next = this;
      next = nullptr;
   }
   List *GetNext() { return next; }
   T     GetData() { return data; }
};

template<typename T>
List<T>::List(T d) {
   data = d;
   next = nullptr;
}

int main() {
   List<char> head('a');
   List<char> *p, *tail;

   tail = &head;  // has only one node here
   for (int i=1; i<26; ++i) {
      p = new List<char>('a'+i);
      p->Add(tail);
      tail = p;
   }

   p = &head;
   if (p == NULL)
      cout << "p is NULL!\n";
   int i =0;
   while (p != NULL) {
      cout << p->GetData();
      p = p->GetNext();
   }
   cout << endl;
}
