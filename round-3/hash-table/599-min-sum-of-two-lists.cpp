class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        
        for (int i = 0; i < list1.size(); i++)
            m[list1[i]] = i;
        
        int least_sum = INT_MAX;
        vector<int> temp;
        for (int i = 0; i < list2.size(); i++) {
            if (m.count(list2[i])) {
                m[list2[i]] += i;
                if (m[list2[i]] < least_sum) {
                    least_sum = m[list2[i]];
                    temp.clear();
                    temp.push_back(i);
                }
                else if (m[list2[i]] == least_sum)
                    temp.push_back(i);
            }
        }
        
        vector<string> res;
        for (int i = 0; i < temp.size(); i++)
            res.push_back(list2[temp[i]]);
        return res;
    }
};

Runtime: 100 ms, faster than 88.23% of C++ online submissions for Minimum Index Sum of Two Lists.
Memory Usage: 28.0 MB, less than 88.89% of C++ online submissions for Minimum Index Sum of Two Lists.
