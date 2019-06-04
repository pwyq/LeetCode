class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            count++;
            if (nums[i] == 0) {
                count = 0;
            }
            if (count > max) {
                max = count;
            }
        }
        return max;
    }
};

// Runtime: 40 ms, faster than 70.38% of C++ online submissions for Max Consecutive Ones.
// Memory Usage: 11.8 MB, less than 62.79% of C++ online submissions for Max Consecutive Ones.
