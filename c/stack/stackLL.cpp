#include <iostream>

using namespace std;

class Node
{
   private:
      int   data;
      Node* next;

   public:
      Node(int d=0);
      ~Node();
};

class Stack
{
   private:
      Node* topPtr;  // NULL if stack is empty

   public:
      Stack();
      ~Stack();
      void Push(int data);
      void Pop();
};

Node::Node(int d)
{
   data = d;
   next = NULL; 
}

Node::~Node()
{
   delete this;
   data = 0;
   next = NULL;
}

/*
Node* Node::NewNode(int data)
{
   //Node* n = (Node*)malloc(sizeof(Node));
   Node* n = new Node;
   n->data = data;
   n->next = NULL;

   return (n);
}

void Node::DeleteNode()
{
   delete Node;
}
*/

Stack::Stack()
{
   topPtr = NULL;
}

Stack::~Stack()
{
   while (topPtr != NULL)
   {
      Node* curr = topPtr;
      topPtr = topPtr->next;
      delete curr;
   }
}

void Stack::Push(int data)
{
   Node newNode(data);
   newNode->next = topPtr;
   topPtr = &newNode;
}

void Stack::Pop()
{
   Node *cTop = topPtr;
   topPtr = topPtr->next;
   delete cTop;
}

int main()
{
   return 0;
}
