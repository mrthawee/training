#include <iostream>

using namespace std;

#define MAX_SIZE 10 

#define OK      0
#define NO_OK  -1

class Stack {
   private:
      int Array[MAX_SIZE];
      int topIndex;

   public:
      Stack();

      bool isEmpty();
      void PrintStack();

      // return OK or NO_OK
      int Push(int data);
      int Pop();
};

Stack::Stack()
{
   for (int i=0; i<MAX_SIZE; i++)
      Array[i] = 0;
   topIndex = -1;
}

bool Stack::isEmpty()
{
   return (topIndex == -1) ? true : false;
}

void Stack::PrintStack()
{
   cout << "Stack : ";
   for (int i=0; i<=topIndex; i++)
      cout << Array[i] << " ";
   cout << " : topIndex = " << topIndex << endl;
}

int Stack::Push(int data)
{
   if (topIndex < MAX_SIZE - 1)
   {
      Array[++topIndex] = data; 
      return OK;
   }
   else
   {
      cout << "Stack is full!" << endl;
      return NO_OK;
   }
}

int Stack::Pop()
{
   if (!isEmpty())
   {
      return (Array[topIndex--]);
   }
   else
   {
      cout << "Stack is Empty!" << endl;
      return NO_OK;
   }
}

int main()
{
   Stack st;

   st.PrintStack();
   st.Push(2);
   st.Push(5);
   st.Push(10);
   st.PrintStack();
   int x = st.Pop();
   cout << "Got " << x << " from Stack." << endl;
   st.PrintStack();
   st.Push(12);
   st.PrintStack();

}
