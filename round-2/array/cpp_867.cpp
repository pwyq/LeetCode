class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        vector<vector<int>> res(col, vector<int>(row, 0));  // vector<data-type> variable_name(size, initialized_value)
        
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                res[i][j] = A[j][i];
            }
        }
        
        return res;
        
        
// Runtime: 28 ms, faster than 89.87% of C++ online submissions for Transpose Matrix.
// Memory Usage: 11.7 MB, less than 50.16% of C++ online submissions for Transpose Matrix.

    }
};
