#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
   private:
      int num_of_vertices;
      vector<int> *Adj;
   public:
      Graph(int V);
      ~Graph();
      void addEdge(int from, int to);
      void BFS(int Start);
      void DFS(int Start);
};

Graph::Graph(int V) {
   this->num_of_vertices = V;
   //num_of_vertices = V;
   Adj = new vector<int>[V];
}

Graph::~Graph() {
   this->num_of_vertices = 0;
   //num_of_vertices = 0;
   delete [] Adj;
}

void Graph::addEdge(int from, int to) {
   Adj[from].push_back(to);
//   Adj[to].push_back(from);
}

void Graph::BFS(int Start) {
   bool* visited = new bool[this->num_of_vertices]();
   //bool* visited = new bool[num_of_vertices]();

   for (int i=0; i<num_of_vertices; i++) {
      visited[i] = false;
   }

   queue<int> queue;
   queue.push(Start);
   vector<int>::iterator i;
   cout << "BFS: ";
   while (!queue.empty()) {
      Start = queue.front();
      //cout << " found " << Start << " ";
      cout << Start << " ";
      visited[Start] = true;
//      cout << "\n set v = " << Start << " to visited\n";
      queue.pop();
      for (i=Adj[Start].begin(); i!=Adj[Start].end(); i++) {
         //cout << "s=" << Start << "  i=" << *i << endl;
         //if (!visited[*i]) {
         if (visited[*i] == false) {
//            cout << "push " << *i << endl;
            queue.push(*i);
            visited[*i] = true;
         }
      }
   }

   cout << endl;
}

void Graph::DFS(int Start) {
   bool* visited = new bool[this->num_of_vertices]();
   //bool* visited = new bool[num_of_vertices]();
   stack<int> stack;
   stack.push(Start);
   vector<int>::iterator i;
   cout << "DFS: ";
   while (!stack.empty()) {
      int top = stack.top();
      cout << top << " ";
      stack.pop();
      visited[top] = true;
      for (i=Adj[top].begin(); i!=Adj[top].end(); i++ ) {
         if (!visited[*i]) {
            stack.push(*i);
         }
      }
   }

   cout << endl;
}

int main() {
   Graph g(4);
   
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 3);
   g.addEdge(1, 3);

/*
   g.addEdge(0, 1);  g.addEdge(0, 2);
   g.addEdge(1, 3);  g.addEdge(2, 3);
   g.addEdge(2, 5);  g.addEdge(3, 6);
   g.addEdge(4, 5);  g.addEdge(4, 6);
*/

   g.DFS(0);

   g.BFS(0);
}
