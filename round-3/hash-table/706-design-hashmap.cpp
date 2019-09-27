// super simple, fast on time, expensive on space
class MyHashMap {
    vector<int> base;
public:
    MyHashMap() {}
    
    void put(int key, int value) {
        if (key >= base.size()) {
            base.resize(key+1, -1);
            base[key] = value;
        }
        else
            base[key] = value;
    }
    
    int get(int key) {
        if (key < base.size() && base[key] != -1)
            return base[key];
        return -1;
    }
    
    void remove(int key) {
        if (key < base.size())
            base[key] = -1;
    }
};

/*
 * Some of the questions which can be asked to the interviewer before implementing the solution

For simplicity, are the keys integers only?
For collision resolution, can we use chaining?
Do we have to worry about load factors?
Can we assume inputs are valid or do we have to validate them?
Can we assume this fits memory?

Cheers !
*/



// some others soln

struct hashNode {
    std::list<pair<int, int>> _list;

    std::list<pair<int, int>>::iterator myFind(int key) {
        return std::find_if(
                _list.begin(), _list.end(),
                [key](pair<int, int> a) { return (a.first == key); });
    }
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        _v = vector<hashNode>(_size);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int k = hash(key);
        auto it = _v[k].myFind(key);
        if (it == _v[k]._list.end()) {
            _v[k]._list.push_back(make_pair(key, value));
        } else {
            it->second = value;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if
     * this map contains no mapping for the key */
    int get(int key) {
        int k = hash(key);
        auto it = _v[k].myFind(key);

        if (it == _v[k]._list.end()) {
            return -1;
        } else {
            return it->second;
        }
    }

    /** Removes the mapping of the specified value key if this map
     * contains a mapping for the key */
    void remove(int key) {
        int k = hash(key);
        auto it = _v[k].myFind(key);

        if (it != _v[k]._list.end()) {
            _v[k]._list.erase(it);
        }
    }

    int hash(int key) {
        return key % _size;
    }


    std::vector<hashNode> _v;
    int _size = 100;
};
