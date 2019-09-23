class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // brute force
        std::map<int, int> freq;
        for (int &i : arr1) {
            freq[i]++;
        }
        vector<int> res;
        for (int i = 0; i < arr2.size(); i++) {
            while (freq[arr2[i]] > 0) {
                res.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }
        
        vector<int> extra;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            while (it->second > 0) {
                extra.push_back(it->first);
                it->second--;
            }
        }
        std::sort(extra.begin(), extra.end());
        res.insert(res.end(), extra.begin(), extra.end());
        return res;
        // close to a 90% runtime soln, but he uses brute force to iterate the whole range for adding the extra elements
    }
};
/*time 50%, space 100%*/
