// one submission, ez
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        // xy = sum of # of non-0 cells
        // yz = sum of max of each row
        // xz = sum of max of each col
        int row = grid.size();
        int col = grid[0].size();
        vector<int> col_max(col, INT_MIN);
        int xy = 0;
        int yz = 0;
        for (int i = 0; i < row; i++) {
            int row_max = INT_MIN;
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != 0) {
                    xy++;
                }
                if (row_max < grid[i][j]) {
                    row_max = grid[i][j];
                }
                if (col_max[j] < grid[i][j]) {
                    col_max[j] = grid[i][j];
                }
            }
            yz += row_max;
        }
        int xz = accumulate(col_max.begin(), col_max.end(), 0);
        return xy + yz + xz;
    }
};
Runtime: 8 ms, faster than 74.94% of C++ online submissions for Projection Area of 3D Shapes.
Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Projection Area of 3D Shapes.
