class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int res = nums[0];
        vector<int> dp(n, 0); 
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int t2 = nums[i] + dp[i-1];
            dp[i] = max(t2, nums[i]);
            // if the previous+current is larger, keep counting; otherwise, reset to current number (which also means the previous-part (no matter how long it was) is decreasing our max)
            res = std::max(res, dp[i]);
        }   
        return res;
    }
};

// MY FIRST TIME to solve a problem with DP!
// TRIED 4 submissions
// Runtime: 4 ms, faster than 98.58% of C++ online submissions for Maximum Subarray.
// Memory Usage: 9.3 MB, less than 66.67% of C++ online submissions for Maximum Subarray.

/*
My original thoughts:

  a b c
  ===     t1 = dp[x] = nums[x] + dp[x-1]
  =====   t2 = dp[x+1] = nums[x+1] + dp[x]
  --===   t3 = dp[x+1] = nums[x+1] + dp[x] - dp[x-1]

from my initial thought, i got following code

t2 = nums[i]+dp[i-1]
t3 = t2 - dp[i-1] = nums[i]    <== Yes, this is a typo (should be `t2-dp[i-2]`), but the TYPO worked!
*/


/*
A resubmission:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i-1], nums[i]);
            res = std::max(res, dp[i]);
        }
        return res;
    }
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Subarray.
Memory Usage: 9.3 MB, less than 83.33% of C++ online submissions for Maximum Subarray.
*/
