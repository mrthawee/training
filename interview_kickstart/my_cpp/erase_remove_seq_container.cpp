// erase - remove idiom
// - applied to sequence containers: vector, deque
// - erase - also move data to make them contiguous ==> Veyr Costly!
// - remove

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void erase_vector() {
    vector<int> v;
    v.push_back(10), v.push_back(20), v.push_back(30), v.push_back(40), v.push_back(40), v.push_back(60), v.push_back(70);

    for(auto &val:v) 
        cout <<"vector val =>" << val << endl;
    
    cout << "remove 3rd (starting from 0th), so remove 40 " << endl;
    v.erase(v.begin() + 3, v.begin() + 4);
    for(auto &val:v) 
        cout <<"vector val =>" << val << endl;
    
    cout << "remove 3rd (starting from 0th), so remove another 40 " << endl;
    v.erase(v.begin() + 3, v.begin() + 4);
    for(auto &val:v) 
        cout <<"vector val =>" << val << endl;
    
    cout << "remove 3rd (starting from 0th) til one before last one, so remove 60 " << endl;
    v.erase(v.begin() + 3, v.end() -1);
    for(auto &val:v) 
        cout <<"vector val =>" << val << endl;
}

// std;:remove(vector.begin(), vector.end(), value)
void remove_vector() {

    cout << "remove_vector()" << endl;
    vector<int> v;
    v.push_back(10), v.push_back(20), v.push_back(30), v.push_back(40), v.push_back(40), v.push_back(60), v.push_back(70);

    for(auto &val:v) 
        cout <<"vector val =>" << val << endl;
    
    cout << "remove all 40: remove(beg, end, val) => remove, BUT NO compact" << endl;
    remove(v.begin(), v.end(), 40);   // this does not compact memory
    for(auto &val:v) 
        cout <<"vector val =>" << val << endl;

    cout << "vector.erase(remove(beg, end, val)) => remove & compact" << endl;
    vector<int> x;
    x.push_back(10), x.push_back(20), x.push_back(30), x.push_back(40), x.push_back(40), x.push_back(60), x.push_back(70);
    x.erase(remove(x.begin(), x.end(), 40), x.end());  // this will compact memroy as well
    for(auto &val:x) 
        cout <<"vector val =>" << val << endl;

    cout << "Zoom in: vector.erase(remove(beg, end, val)) => remove & compact" << endl;
    vector<int> y;
    y.push_back(10), y.push_back(20), y.push_back(30), y.push_back(40), y.push_back(40), y.push_back(60), y.push_back(70);
    // y.erase(remove(y.begin(), y.end(), 40), y.end());  // this will compact memroy as well
    auto iterbeg =remove(y.begin(), y.end(), 40);
    cout << "size of vector after remove() = " << y.size() << endl;
    y.erase(iterbeg, y.end());
    cout << "size of vector after erase() = " << y.size() << endl;
    for(auto &val:y) 
        cout <<"vector val =>" << val << endl;

}

void remove_with_lambda_function() {
    cout << "remove_with_lambda_function()" << endl;
    vector<int> v;
    v.push_back(10), v.push_back(20), v.push_back(30), v.push_back(40), v.push_back(40), v.push_back(60), v.push_back(70);

    cout << "before remove:" << endl;
    for (auto &val: v) {
        cout << "val => " << val << endl;
    }

    // lambda function
    auto iterbeg = remove_if(v.begin(), v.end(), [](int val) {
        if (val == 40) {
            return true;
        }

        return false;
    });

    cout << "after remove:" << endl;
    for (auto &val: v) {
        cout << "val => " << val << endl;
    }
}

int main() {
    erase_vector();
    remove_vector();
    remove_with_lambda_function();

    return 0;
}
