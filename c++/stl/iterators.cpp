/*
 * Iterators:
 * 1. Random Access Iterator: vector, deque, array
 */ 

vector<int> itr;
itr = itr + 5;  // advance itr by 5 
itr = itr - 4;
if (itr2 > itr1) ...
++itr;  // faster than itr++
--itr;

/*
 * 2. Bidirectional Iterator: list, set/multiset, map/multimap
 */
list<int> itr;
++itr;
--itr;
can't itr = itr +5;  // can't!!

/*
 * 3. Forward Iterator: forward_list
 */
forward_list<int> itr;
++itr;
can't --itr; // can't!!!

// Unordered containers provide "at least" forward iterators.

/*
 * 4. Input Iterator: read and process values while iterating forward.
 *    - Can't move backward
 */
int x = *itr;

/*
 * 5. Output Iterator: output values while iterating forward.
 *    - Can't move backward
 */
*itr = 100;


// Every container has a iterator and a const_iterator
set<int>::iterator itr;
set<int>::const_iterator citr;  // read-only access to container elements

set<int> myset = {2,4,5,1,9};
for (citr = myset.begin(); citr != myset.end(); ++citr) {
   cout << *citr << endl;
   // *citr = 3; -> Error: read-only
}

for_each(myset.cbegin(), myset.cend(), MyFunction); // only in c++ 11

// Iterator Functions:
advance(itr, 5);  // move itr forward 5 spots.  itr += 5;
distance(itr1, itr2);   // measure the distance between itr1 and itr2


/*
 * Iterator Adaptor (Predefined Iterator)
 * - special, more powerful iterators
 * - there are 4 kinds of them
 *   1. Insert iterator
 *   2. Stream iterator
 *   3. Reverse iterator
 *   4. Move iterator (new in c++ 11)
 */

// 1. Insert Iterator:
vector<int> vec1 = {4,5}
vector<int> vec2 = {12, 14, 16, 18};
vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
insert_iterator<vector<int>> i_itr(vec2, it);
copy(vec1.begin(), vec1.end(), // source
     i_itr);                   // destination
     // vec2: {12, 14, 4, 5, 16, 18}
// Other insert iterators: back_insert_iterator, front_insert_iterator

// 2. Stream Iterator:
vector<string> vec4;
copy(istream_iterator<string>(cin), istream_iterator<string>(),
      back_inserter(vec4)); // cin strings into vec4

copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, " ")); // cout vec4

// combining the cin strings and cout to 1 statement
copy(istream_iterator<string>(cin), istream_iterator<string>(),
            ostream_iterator<string>(cout, " "));

// 3. Reverse Iterator:
vector<int> vec = {4,5,6,7};
reverse_iterator<vector<int>::iterator> ritr;
for (ritr=vec.begin(); ritr!=ritr.rend(); ritr++)
   cout << *ritr  << " ";
cout << endl;   //  print: 7 6 5 4

