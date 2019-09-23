class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        int row = nums.size();
        int col = nums[0].size();
        if (r * c != row * col) return nums;
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        
        vector<int> temp;
        for (auto & i: nums) {
            for (auto & j: i) {
                temp.push_back(j);
            }
        }
        
        int ct = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = temp[ct++];
            }
        }
        return res;
    }
};

/*Runtime: 32 ms, faster than 92.84% of C++ online submissions for Reshape the Matrix.
Memory Usage: 12.2 MB, less than 8.00% of C++ online submissions for Reshape the Matrix.*/
