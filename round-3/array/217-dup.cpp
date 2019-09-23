class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int & i : nums) {
            if (++cnt[i] > 1)
                return true;
        }
        return false;
    }
};

/* Runtime: 48 ms, faster than 30.81% of C++ online submissions for Contains Duplicate.
Memory Usage: 16.5 MB, less than 70.33% of C++ online submissions for Contains Duplicate.*/
// or use sort, then compare nums[i] == nums[i+1]
