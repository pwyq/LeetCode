class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        // int numElem = nums.size() * nums[0].size();
        // int targetElem = r * c;
        // if (numElem != targetElem) {
        //     return nums;
        // }
        // queue<int> q;
        // for (auto row : nums) {
        //     for (auto col : row) {
        //         q.push(col);
        //     }
        // }
        // vector<vector<int>> res(r, vector<int>(c, 0));
        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         res[i][j] = q.front();
        //         q.pop();
        //     }
        // }
        // return res;
        
        // From one post
        int row = nums.size();
        int col = nums[0].size();
        int total = row * col;
        if (total != r * c) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        // for (int i = 0; i < total; i++) {
        //     // cout << "i/c = " << i/c << ", i%c = " << i%c << endl;
        //     // cout << "i%col = " << i/col << ", i%col = " << i%col << endl;
        //     res[i/c][i%c] = nums[i/col][i%col];     // super smart
        // }
        
        for (int i = 0, k = 0; i < row; i++)
            for (int j = 0; j < col; j++, k++)
                res[k / c][k % c] = nums[i][j]; // save mem usage
        return res;
    }
};


// Runtime: 32 ms, faster than 98.60% of C++ online submissions for Reshape the Matrix.
// Memory Usage: 12.5 MB, less than 23.94% of C++ online submissions for Reshape the Matrix.

// Runtime: 36 ms, faster than 90.13% of C++ online submissions for Reshape the Matrix.
// Memory Usage: 11.9 MB, less than 67.53% of C++ online submissions for Reshape the Matrix.

// Runtime: 36 ms, faster than 90.13% of C++ online submissions for Reshape the Matrix.
// Memory Usage: 11.7 MB, less than 76.96% of C++ online submissions for Reshape the Matrix.
