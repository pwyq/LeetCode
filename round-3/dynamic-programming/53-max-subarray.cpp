class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
