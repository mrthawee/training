#include <iostream>
#include <stdio.h> // getchar()

using namespace std;

#define MAX_LEVELS 10

class Cstack {
   public:
      int rings[MAX_LEVELS];  // Array of ring values
      int tos;                // Top of stack index
      void populate(int size);   // Initialize stack
      void clear(int);           // Clear the stack
      void push(int n);
      int  pop(void);
} stacks[3];  // three poles

void Cstack::populate(int size) {
   for (int i=0; i<size; ++i) {
      rings[i] = i+1;
   }

   tos = -1;
}

void Cstack::clear(int size) {
   for (int i=0; i<size; ++i) {
      rings[i] = 0;
   }

   tos = size - 1;
}

void Cstack::push(int n) {
   rings[tos--] = n;
}

int Cstack::pop(void) {
   int n = rings[++tos];
   rings[tos] = 0;
   return n;
}

//void move_stacks(int src, int desc, int other, int n);
void move_stacks(int n, int src, int dest, int other);
void move_a_ring(int source, int dest);
void print_stacks(void);
void pr_chars(char ch, int n);

int stack_size = 3;

int main() {
   stacks[0].populate(stack_size);
   stacks[1].clear(stack_size);
   stacks[2].clear(stack_size);
   print_stacks();
   move_stacks(stack_size, 0, 2, 1);

   return 0;
}

void move_stacks(int n, int src, int dest, int other) {
   if (n == 1) {
      move_a_ring(src, dest);
   } else {
      move_stacks(n-1, src, other, dest);
      move_a_ring(src, dest);
      move_stacks(n-1, other, dest, src);
   }
}

void move_a_ring(int src, int dest) {
   int n = stacks[src].pop();    // Pop off source
   stacks[dest].push(n);         // Push onto dest
   print_stacks();               // Show new state
}

void print_stacks(void) {
   int n = 0; 
   for (int i=0; i<stack_size; ++i) {
      for (int j=0; j<i; ++j) {
         n = stacks[j].rings[i];
         cout << "stacks["<<j<<"].rings["<<i<<"] : n=" << n << endl;
         pr_chars('.', 6 - n);
         pr_chars('#', 1 * n);
         pr_chars('%', 6 - n);
      }
      cout << endl;
   }

   getchar();
}

void pr_chars(char ch, int n) {
   for (int i=0; i<n; ++i) {
      cout << ch;
   }
}
