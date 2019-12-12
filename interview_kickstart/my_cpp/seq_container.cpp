// C++ STL Sequence Container: vector, list
// vector : contiguous memory allocation
// list : doubly linked list
#include <iostream>
#include <vector>
#include <list>

// sort: works with random access iterator
//   vector - ok
//   list - Not ok, it is a bi-directional iterator
#include <algorithm>

using namespace std;

void my_vector() {
  cout << "my_vector()" << endl;
  vector<int> v;
  v.push_back(110);
  v.push_back(201);
  v.push_back(40);
  v.push_back(50);
  cout << "Size => " << v.size() << endl;

  // Iterator are similar to pointers
  vector<int>::iterator itr = v.begin();
  cout <<*itr<<endl;
  cout <<*(itr+1)<<endl;
  cout <<*(itr+3)<<endl;
  cout <<*(itr+5)<<endl;

  for (; itr!= v.end(); itr++) {
    cout << "val => " << *itr << endl;
  }

  sort(v.begin(), v.end());
  itr = v.begin();
  for (; itr!= v.end(); itr++) {
    cout << "val => " << *itr << ", ";
  }
  cout << endl;

  v.clear();
  cout << "after v.clear() size => " << v.size() << endl;
}

void my_list() {
  cout << "my_list()" << endl;
  list<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(40);
  v.push_back(50);
  cout << "Size => " << v.size() << endl;

  // Iterator are similar to pointers
  // list<int>::iterator itr = v.begin();
  auto itr = v.begin();  // we can use 'auto'
  /*
  // list doesn't have direct access like vector
  cout <<*itr<<endl;
  cout <<*(itr+1)<<endl;
  cout <<*(itr+3)<<endl;
  cout <<*(itr+5)<<endl;
  */

  for (; itr!= v.end(); itr++) {
    cout << "val => " << *itr << endl;
  }

  v.clear();
  cout << "after v.clear() size => " << v.size() << endl;
}

void my_array() {
  cout << "my_array()" << endl;
  int arr[] = { 100, 20, 300, 34, 44 };
  int *beg = &arr[0];
  int *end = &arr[0] + (sizeof(arr)/sizeof(int));
  
  sort(beg, end);
  for (; beg != end; beg++) {
    cout << "val => " << *beg << endl;
  }
}

int main() {
  my_vector();
  my_list();
  my_array();
  return 0;
}
