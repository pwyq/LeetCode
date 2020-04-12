/**
 * File              : 1130-min-cost-tree-from-leaf-values.cpp
 * Author            : Yanqing Wu <meet.yanqing.wu@gmail.com>
 * Date              : 17.10.2019
 * Last Modified Date: 17.10.2019
 * Last Modified By  : Yanqing Wu <meet.yanqing.wu@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n-len+1; i++) {
                int j = i+len-1;
                cout << i << ", " << j << ", " << len << endl;
                for (int k = i; k < j; k++) {
                    int l = findMax(arr, i, k);
                    int r = findMax(arr, k+1, j);
                    int p = l * r;
                    int res = dp[i][k]+dp[k+1][j]+p;
                    dp[i][j] = min(res, dp[i][j]);
                }
            }
        }

        /*
        for (auto row : dp) {
            for (auto col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
        */
        return dp[0][n-1];
    }

    int findMax(vector<int> a, int s, int e) {
        int res = a[s];
        for (int i = s+1; i <= e; i++) {
            if (res < a[i]) {
                res = a[i];
            }
        }
        return res;
    }
};

int main() {
    vector<int> a1 = {1,2,3,4};
    int r1 = Solution().mctFromLeafValues(a1);
    assert(r1 == 20);

    vector<int> a2 = {6,2,4};
    int r2 = Solution().mctFromLeafValues(a2);
    assert(r2 == 32);

    vector<int> a3 = {7,12,8,10};
    int r3 = Solution().mctFromLeafValues(a3);
    assert(r3 == 284);

    return 0;
}
