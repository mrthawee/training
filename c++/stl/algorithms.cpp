/*
 * Algorithms
 * - mostly loops
 */

vector<int> vec = { 4, 2, 5, 1, 3, 9 };
vector<int>::iterator itr = min_element(vec.begin(), vec.end()); // itr -> 1

// Note 1: Algorithm always process ranges in a half-open way: [begin, end)
sort(vec.begin(), itr); // vec: {2,4,5,1,3,9}

reverse(itr, vec.end);  // vec: {2,4,5,9,3,1} => itr => 9

// Note 2: 
vector<int> vec2(3);
copy(itr, vec.end(),  // source
     vec2.being());   // destination
     // Warning!!! vec2 needs to have at least space for 3 elements

// Note 3:
vector<int> vec3;
copy(itr, vec.end(), back_inserter(vec3)); // insert instead of overwriting
                  // back_insert_iterator  // work, but not efficient
                                           // because one at a time

vec3.insert(vec3.end(), itr, vec.end()); // efficient and safe

// Note 4:
bool isOdd(int i) {
   return i%2;
}

int main() {
   vector<int> vec = { 2, 4, 5, 9, 2 };
   vector<int>::iterator itr = find_if(vec.begin(), vec.end(), isOdd);
                              // itr -> 5

// Note 5: Algorithm with native c++ array
int arr[4] = { 6,3,7,4};
sort(arr, arr+4);  // work fine : { 3,4,6,7 } because pointer/array can be treated as an iterator
