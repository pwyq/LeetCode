class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        unordered_map<int, int> m;
        for (int i : arr1)
            m[i]++;
        for (int i : arr2)
            m[i]++;
        for (int i : arr3)
            m[i]++;
        
        vector<int> res;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 3) {
                res.push_back(it->first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
