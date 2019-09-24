class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            vector<int> row(i+1, 0);
            res.push_back(row);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    res[i][j] = 1;
                    continue;
                }
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};

/*Runtime: 4 ms, faster than 60.46% of C++ online submissions for Pascal's Triangle.
Memory Usage: 8.7 MB, less than 92.59% of C++ online submissions for Pascal's Triangle.*/
