#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
    vector<int> base;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        cout << "key << " << key << ", val = " << value << endl;
        if (key >= base.size()) {
            cout << "RESIZING" << endl;
            base.resize(key+1, -1);
            base[key] = value;
        }
        else {
            base[key] = value;
        }
        print_vec();
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (key < base.size() && base[key] != -1) {
            return base[key];
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (key < base.size()) {
            base[key] = -1;
        }
    }

    void print_vec() {
        for (int i : base)
            cout << i << " ";
        cout << endl;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 */


int main() {
    MyHashMap *hashMap = new MyHashMap();
    hashMap->put(1, 1);          
    hashMap->put(2, 2);         
    cout << hashMap->get(1) << endl;            // returns 1
    cout << hashMap->get(3) << endl;            // returns -1 (not found)
    hashMap->put(2, 9);          // update the existing value
    cout << hashMap->get(2) << endl;            // returns 9 
    hashMap->remove(2);          // remove the mapping for 2
    cout << hashMap->get(2) << endl;            // returns -1 (not found) 
    return 0;
}
