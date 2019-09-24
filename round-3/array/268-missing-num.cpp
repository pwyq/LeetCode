class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0, j = 0; i < nums.size(); i++, j++) {
            if (nums[i] != j) {
                return j;
            }
        }
        return nums.size();
    }
};

/*
Runtime: 28 ms, faster than 28.08% of C++ online submissions for Missing Number.
Memory Usage: 9.9 MB, less than 64.71% of C++ online submissions for Missing Number.
*/
