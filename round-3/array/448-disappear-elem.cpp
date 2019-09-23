class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // value negate approach
        // marks and sweep
        
        for (int i = 0; i < nums.size(); i++) {
            int val = std::abs(nums[i]) - 1;
            if (nums[val] > 0) nums[val] = -nums[val];
        }
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i+1);    // since we're 0-based
        }
        return res;
    }
};
