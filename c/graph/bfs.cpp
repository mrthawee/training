// bfs.cpp
// Written by Bibek Subedi
// http://www.programming-techniques.com/2012/07/breadth-first-search-in-c-algorithm-and.html

#include <iostream>
#include <ctime>

using namespace std;

// Performs the breadth first graph search for both directed and undirected
// graphs.  This algorithm explores all the findable nodes in "layers".
// @author Bibek Subedi

// Class Queue represents a Queue data structure which is first in first out
// (FIFO) structured. It has operations like Enqueue which adds an element at
// the rear side and Dequeue which removes the element from front.

struct node {
   int info;
   node *next;
};

class Queue {
   private:
      node *front;
      node *rear;
   public:
      Queue();
      ~Queue();
      bool isEmpty();
      void enqueue(int);
      int  dequeue();
      void display();
};

void Queue::display() {
   node *p = new node;
   p = front;
   if (front == NULL) {
      cout << "Queue is empty: nothing to be displayed.\n";
   } else {
      while ( p != NULL) {
         cout << endl << p->info;
         p = p->next;
      }
   }
}

Queue::Queue() {
   front = NULL;
   rear = NULL;
} 

Queue::~Queue() {
   delete front;
}

void Queue::enqueue(int data) {
   node *temp = new node();
   temp->info = data;
   temp->next = NULL;
   if (front == NULL) {
      front = temp;
   } else {
      rear->next = temp;
   }
   rear = temp;
}

int Queue::dequeue() {
   node *temp = new node();
   int value;

   if (front == NULL) {
      cout << "Queue is empty: nothing to be dequeued.\n";
   } else {
      temp = front;
      value = temp->info;
      front = front->next;
      delete temp;
   }
   
   return value;
}

bool Queue::isEmpty() {
   return (front == NULL);
}

// Class Graph represents a Graph [V,E] having vertices V and edge E.

class Graph {
   private:
      int n;  // n is the number of vertices in the graph
      int **A; // A stores the edges between two vertices
   public:
      Graph(int size=2);
      ~Graph();
      bool isConnected(int, int);
      void addEdge(int u, int v);
      void BFS(int);
};

Graph::Graph(int size) {
   int i, j;

   if (size < 2) 
      n = 2;  // gotta have at least 2 vertices and 1 edge
   else 
      n = size;

   A = new int*[n];
   for (i=0; i<n; ++i) {
      A[i] = new int[n];
   }

   for (i=0; i<n; ++i) {
      for (j=0; j<n; ++j) {
         A[i][j] = 0;
      }
   }
}

Graph::~Graph() {
   for (int i=0; i<n; i++ ) {
      delete [] A[i];
   }

   delete [] A;
}

// Checks if two given vertices are connected by an edge
// @param u vertex
// @param v vertex
// @return true if connected falase if not connected
bool Graph::isConnected(int u, int v) {
   //return (A[u-1][v-1] == 1);
/*
   if (A[u-1][v-1] == 1) {
      cout << "chk (" << u << ", " << v << ") is connected\n";
   }
*/
   return (A[u-1][v-1] == 1);
}

// Add and edge E to the graph G
// @param u vertex
// @param v vertex
void Graph::addEdge(int u, int v) {
   A[u-1][v-1] = A[v-1][u-1] = 1;
}

// Performs Breadth First Search
// @param s initial vertex
void Graph::BFS(int s) {
   Queue Q;

   // Keeps track of explored vertices
   bool *explored = new bool[n+1];

   // Initialized all vertices as unexplored
   for (int i=0; i<n; i++) {
      explored[i] = false;
   }

   // Push initial vertex to the queue
   Q.enqueue(s);
   explored[s] = true;  // mark it as explored
   cout << "BFS starting from vertex " << s << " : " << endl;

   // Unless the queue is empty
   while (!Q.isEmpty()) {
      // Pop the vertex from the queue
      int v = Q.dequeue();

      // display the explored vertices
      cout << v << " ";

      // From the explored vertex v try to explore all the connected vertices
      for (int w=0; w<n; w++) {
         // Explores the vertex w if it is connected to v and unexplored
         if (isConnected(v, w) && !explored[w]) {
            // adds the vertex w to the queue
            Q.enqueue(w);

            // marsk the vertex w as visited
            explored[w] = true;
         }
      }
   }

   cout << endl;
   delete [] explored;
}

int main() {

   // Creates a graph with 12 vertices
   Graph g(12);

   // Adds edges to the graph
   g.addEdge(1, 2);  g.addEdge(1, 3);
   g.addEdge(2, 4);  g.addEdge(3, 4);
   g.addEdge(3, 6);  g.addEdge(4, 7);
   g.addEdge(5, 6);  g.addEdge(5, 7);

   clock_t t1;
   t1 = clock();

   // Explores all vertices findable from vertex 1
   g.BFS(1);
   float diff = (double)(clock() - t1)/CLOCKS_PER_SEC;
   cout << "The time taken for BFS: " << diff << endl;
}
