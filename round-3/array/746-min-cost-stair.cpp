// Runtime: 8 ms, faster than 59.67% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 8.9 MB, less than 51.16% of C++ online submissions for Min Cost Climbing Stairs.

// BACKWORDS is 8ms faster than FORWARDS
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s = cost.size();
        vector<int> spend(s, 0);
        
        // BACKWORDS
        spend[s-1] = cost[s-1];
        spend[s-2] = cost[s-2];
        
        for (int i = s-3; i >= 0; i--) {
            spend[i] = cost[i] + min(spend[i+1], spend[i+2]);
        }
        return min(spend[0], spend[1]);
                                   
        // FORWARDS
        /*
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
        }
        for (int i = 0; i < dp.size(); i++) {
            cout << dp[i] << " ";
        }
        cout << endl;
        return min(dp[n-2], dp[n-1]);
        */
    }
};

// [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//  0   1   2  3  4   5   6  7   8   9
//  0 ..........................N-2  N-1
 
// f[0] = cost[0] + min(f[1], f[2]);
// f[1] = cost[1] + min(f[2], f[3]);
// f[2] = cost[2] + min(f[3], f[4]);
// f[3] = cost[3] + min(f[4], f[5])
// f[4] = cost[4] + min(f[5], f[6])   = cost[4] + min(cost[5] + cost[9] + min(cost[6]+min(cost[7], cost[8]), cost[7]),
//                                                    cost[6] + cost[9] + min(cost[7], cost[8]))
//                                    = cost[4] + cost[9] + min(cost[5] + min(cost[6]+min(cost[7], cost[8]), cost[7]), 
//                                                              cost[6] + min(cost[7], cost[8]))
// f[5] = cost[5] + min(f[6], f[7])   = cost[5] + min(cost[6] + cost[9] + min(cost[7], cost[8]), cost[7] + cost[9])
//                                    = cost[5] + cost[9] + min(cost[6]+min(cost[7], cost[8]), cost[7])
// f[6] = cost[6] + min(f[7], f[8])   = cost[6] + min(cost[7]+cost[9], cost[8]+cost[9]);
//                                    = cost[6] + cost[9] + min(cost[7], cost[8]);
// f[7] = cost[7] + min(f[8], f[9])   = cost[7] + min(cost[8]+cost[9], cost[9])
//                                    = cost[7] + cost[9];
// f[8] = cost[8] + min(f[9], f[10])  = cost[8] + cost[9];   => NOTE! for backwards, this should be f[8] = cost[8], since we can directly jump to the top (2-stair jump!)
// f[9] = cost[9] + min(f[10], f[11]) = cost[9];

// f[10] = 0;
// f[11] = 0;


// [10,99,1,2,3,9,99,0,100,0,0,100] 22
