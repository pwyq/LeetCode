class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> m(nums.size()+1, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        
        int rept;
        int miss;
        for (int i = 1; i < m.size(); i++) {
            if (m[i] == 2)
                rept = i;
            else if (m[i] == 0)
                miss = i;
        }
        return {rept, miss};
    }
};

Runtime: 36 ms, faster than 86.64% of C++ online submissions for Set Mismatch.
Memory Usage: 11.3 MB, less than 25.00% of C++ online submissions for Set Mismatch.
