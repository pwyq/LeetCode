class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;    // use ordered map
        for (int i : nums)
            m[i]++;
        
        int res = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            int curr = it->first;
            int curr_val = it->second;
            // cout << "curr = " << curr << ", val = " << curr_val;
            it++;
            if (it == m.end()) break;
            int next = it->first;
            int next_val = it->second;
            // cout << " | next = " << next << ", val = " << next_val << endl;
            if (curr == (next-1)) {
                if ((curr_val+next_val) > res)
                    res = curr_val + next_val;
            }
            it--;
        }
        return res;
    }
};

Runtime: 112 ms, faster than 41.97% of C++ online submissions for Longest Harmonious Subsequence.
Memory Usage: 20.7 MB, less than 33.33% of C++ online submissions for Longest Harmonious Subsequence.