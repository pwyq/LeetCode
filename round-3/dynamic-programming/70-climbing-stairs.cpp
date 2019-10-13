// I did it!! from O(2^n) to O(n)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        // recursive brute force (TLE) O(2^n)
        // Think of binary tree, the total leaves till n-th level is 2^n
        // which is huge!!
        int count = 0;
        countClimb(0, count, n);
        return count;
    }
    
    
    int countClimb(int i, int &count, int n) {
        // cout << i << ", " << count << ", " << n << endl;
        if (i > n) return 0;
        if (i == n) {
            count += 1;
            return 0;
        }
        return countClimb(i+1, count, n) || countClimb(i+2, count, n);
    }

    int climbStairs2(int n) {
        // DP O(n)
        if (n == 1) return 1;
        vector<int> dp(n, 0);

        dp[n-1] = 1;
        dp[n-2] = 2;
        for (int i = n-3; i >= 0; i--) {
            dp[i] += dp[i+1] + dp[i+2];
        }
        return dp[0];
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
//Memory Usage: 8.5 MB, less than 25.00% of C++ online submissions for Climbing Stairs.
    }
};

int main() {
    // 2^10 = 1024
    // 2^20 ~= 1M (1048576)
    // 2^30 ~= 1B
    for (int i = 1; i < 31; i++) {
        int r1 = Solution().climbStairs(i);
        int r2 = Solution().climbStairs2(i);
        assert(r1 == r2);
    }
    return 0;
}
