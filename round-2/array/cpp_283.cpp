class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        for (int i = 0; i < nums.size()-zeros; i++) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                zeros++;
                i--;
            }
        }
        return;
    }
};

// Runtime: 20 ms, faster than 35.18% of C++ online submissions for Move Zeroes.
// Memory Usage: 9.4 MB, less than 76.90% of C++ online submissions for Move Zeroes.
