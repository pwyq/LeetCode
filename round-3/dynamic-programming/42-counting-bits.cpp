class Solution {
public:
    vector<int> countBits(int num) {
        // thanks dalao
        vector<int> res(num+1, 0);
        for (int i = 1; i <= num; i++) {
            // i & (i-1) drops the lowest set bit
            res[i] = res[i & (i-1)] + 1;
        }
        return res;
    }
};

// 0 1 2 3  4 5 6 7, 8 9 10 11 12 13 14 15 16
// 0 1 1 2, 1 2 2 3, 1 2 2  3, 2  3  3  4, 1

/*
dp[0] = 0;
dp[1] = dp[0] + 1;
dp[2] = dp[0] + 1;
dp[3] = dp[1] + 1;

dp[4] = dp[0] + 1;
dp[5] = dp[4] + 1;
dp[6] = dp[4] + 1;
dp[7] = dp[5] + 1;

dp[8] = dp[0] + 1;
dp[9] = dp[8] + 1;
dp[10] = dp[8] + 1;
dp[11] = dp[9] + 1;

dp[12] = dp[1] + 1;
dp[13] = dp[12] + 1;
dp[14] = dp[12] + 1;
dp[15] = dp[14] + 1;
*/
