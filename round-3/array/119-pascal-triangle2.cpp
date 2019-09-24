class Solution {
public:
    vector<int> getRow(int n) {
        // n = n + 1;  // The problem shift the index
        // vector<vector<int>> res;
        // for (int i = 0; i < n; i++) {
        //     vector<int> row(i+1, 0);
        //     res.push_back(row);
        //     for (int j = 0; j <= i; j++) {
        //         if (j == 0 || j == i) {
        //             res[i][j] = 1;
        //             continue;
        //         }
        //         res[i][j] = res[i-1][j-1] + res[i-1][j];
        //     }
        // }
        // return res[n-1];

        // we can only use 2*k space
        // note that row k has k elements; (in this question)
        vector<vector<int>> res(2, vector<int>(++n));
        int row = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                row = i % 2;
                if (j == 0 || j == i) {
                    res[row][j] = 1;
                    continue;
                }
                if (row % 2 == 1) 
                    res[row][j] = res[row-1][j-1] + res[row-1][j];
                else
                    res[row][j] = res[row+1][j-1] + res[row+1][j];
            }
        }
        return res[row];
    }
};
/*
Runtime: 4 ms, faster than 59.13% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 8.8 MB, less than 19.35% of C++ online submissions for Pascal's Triangle II.
*/

// After optimization
/*
Runtime: 4 ms, faster than 59.13% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Pascal's Triangle II.
*/
