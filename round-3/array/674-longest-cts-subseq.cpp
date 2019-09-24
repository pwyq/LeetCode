class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i-1] < nums[i])
                res = max(res, ++cnt);
            else
                cnt = 1;
        }
        return res;
    }

    /* similar runtime & space
    int findLengthOfLCIS(vector<int>& nums) {
        // DP!
        
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n);
        
        int res = 1;
        dp[0] = 1;  // base case
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1;
            else
                dp[i] = 1;
            res = max(res, dp[i]);
        }
        return res;
    }
    */
};

/*Runtime: 16 ms, faster than 58.06% of C++ online submissions for Longest Continuous Increasing Subsequence.
Memory Usage: 9.4 MB, less than 72.22% of C++ online submissions for Longest Continuous Increasing Subsequence.*/
