class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        // compare bottom-right neighbor
        
        // int row = matrix.size();
        // int col = matrix[0].size();
        // for (int i = 0; i < row; i++) {
        //     for (int j = 0; j < col; j++) {
        //         if ((i+1 < row) && (j+1 < col)) {
        //             if (matrix[i][j] != matrix[i+1][j+1]) {
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // return true;
        
        // compare top-left neighbor
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
// Runtime: 16 ms, faster than 60.32% of C++ online submissions for Toeplitz Matrix.
// Memory Usage: 9.8 MB, less than 63.76% of C++ online submissions for Toeplitz Matrix.
    
    
// Runtime: 12 ms, faster than 94.35% of C++ online submissions for Toeplitz Matrix.
// Memory Usage: 9.7 MB, less than 77.87% of C++ online submissions for Toeplitz Matrix.
};
