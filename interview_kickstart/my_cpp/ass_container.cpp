// Associatve container:
// - Stored in key : value pair
// - 2 types of associative containers
//   1. ordered: map, multimap, set, multiset ==> Red-Black Tree or Balanced Binary Tree
//   2. unordered: unordered_map, unordered_multimap, unordered_set, unordered_multiset ==> Hash Table

// Cover here: map, multimap, unordered_map, unordered_multimap
#include <iostream>
#include <map>              // map , multimap
#include <unordered_map>    // unordered_map, unordered_multimap

using namespace std;

void my_map() {
    cout << "pair" << endl;
    pair<int, int> p = make_pair(10, 20);
    cout << p.first << " : " << p.second << endl;

    cout << "my_map()" << endl;
    map<int, int> mp;
    mp[4] = 400;
    mp[3] = 300;

    mp.insert(make_pair(10, 100));
    mp[7] = 700;

    // insert to existing key -> discarded!
    mp.insert(make_pair(10, 200));
    // update to existing key -> overwrite val
    mp[10] = 222;

    // map iterator
    // - returns sub-pair
    // - always sorted in the order of the keys
    // - internal data structure = red-black tree
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << "-" << it->second << endl;
    }
}

void my_multimap() {
    // No [], need make_pair(x, y) 

    cout << "my_multimap()" << endl;
    multimap<int, int> mp;
    mp.insert(make_pair(4, 400));
    mp.insert(make_pair(10, 700));
    mp.insert(make_pair(3, 300));
    mp.insert(make_pair(10, 900));
    mp.insert(make_pair(10, 1000));

    // sorted order of keys
    // BUT allows dup keys
    // SO, it can't do mp[10] because it can't tell with key [10] to refer to
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << "--" << it->second << endl;
    }
}

void my_unordered_map() {
    cout << "my_unordered_map()" << endl;
    unordered_map<int, int> mp;
    mp[4] = 400;
    mp[3] = 300;

    mp.insert(make_pair(10, 100));
    mp[7] = 700;

    // insert to existing key -> discarded!
    mp.insert(make_pair(10, 200));
    // update to existing key -> overwrite val
    mp[10] = 222;

    // map iterator
    // - returns sub-pair
    // - always sorted in the order of the keys
    // - internal data structure = red-black tree
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << "-" << it->second << endl;
    }
}

void my_unordered_multimap() {
    // No [], need make_pair(x, y) 

    cout << "my_unordered_multimap()" << endl;
    unordered_multimap<int, int> mp;
    mp.insert(make_pair(4, 400));
    mp.insert(make_pair(10, 700));
    mp.insert(make_pair(3, 300));
    mp.insert(make_pair(10, 900));
    mp.insert(make_pair(10, 1000));

    // sorted order of keys
    // BUT allows dup keys
    // SO, it can't do mp[10] because it can't tell with key [10] to refer to
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << "--" << it->second << endl;
    }
}
int main() {
    my_map();
    my_multimap();
    my_unordered_map();
    my_unordered_multimap();
    
    return 0;
}
