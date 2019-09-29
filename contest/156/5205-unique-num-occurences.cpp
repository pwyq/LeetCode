class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i : arr) {
            m[i]++;
        }
        
        set<int> exist;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (exist.insert(it->second).second == false) {
                return false;
            }
        }
        return true;
    }
};
