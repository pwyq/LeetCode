/**
 * File              : 877-stone-game.cpp
 * Author            : Yanqing Wu <meet.yanqing.wu@gmail.com>
 * Date              : 16.10.2019
 * Last Modified Date: 16.10.2019
 * Last Modified By  : Yanqing Wu <meet.yanqing.wu@gmail.com>
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        // dp[i][j] represents the max difference between first-picker and second-picker from piles[i] to piles[j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = p[i];
        /*
        for (int d = 1; d < n; d++) {
            for (int i = 0; i < n - d; i++) {
                dp[i][i + d] = max(p[i] - dp[i + 1][i + d], p[i + d] - dp[i][i + d - 1]);
            }
        }
        */
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n-j; i++) {
                cout << i << ", " << j+i << endl;
                dp[i][j+i] = max(p[i] - dp[i+1][j+i], p[j+i]-dp[i][j+i-1]);
            }
        }
        /*
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                dp[i][j] = max(p[i-1]-dp[i][j], p[j]-dp[i-1][j-1]);
            }
        }
        */

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][n - 1] > 0;
    }
};

int main() {
    vector<int> test = {1,2,3,4,5,6};
    bool res = Solution().stoneGame(test);
    return 0;
}


/*
1 1 2 2 3 3 
0 2 1 3 2 4 
0 0 3 1 4 2 
0 0 0 4 1 5 
0 0 0 0 5 1 
0 0 0 0 0 6 
*/
