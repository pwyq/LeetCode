class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size();
        int col = M[0].size();
        if ((row == 0 && col == 0) || (row == 1 && col == 1)) {
            return M;
        }
        vector<vector<int>> res(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0) {
                    if (j == 0) {
                        // top left corner
                        int sum = M[i][j];
                        if (i+1 < row) {
                            if (j+1 < col) {
                                // x o
                                // o o
                                sum += M[i+1][j] + M[i][j+1] + M[i+1][j+1];
                                res[i][j] = floor(sum/4);
                            }
                            else {
                                // x|
                                // o|
                                sum += M[i+1][j];
                                res[i][j] = floor(sum/2);
                            }
                        }
                        else {
                            if (j+1 < col) {
                                // x o
                                // ----
                                sum += M[i][j+1];
                                res[i][j] = floor(sum/2);
                            }
                            else {
                                // x|
                                // --
                                res[i][j] = floor(sum);
                            }
                        }
                    }
                    else {
                        // first row but not the first grid
                        int sum = M[i][j-1] + M[i][j];
                        if (i+1 < row) {
                            if (j+1 < col) {
                                // -----
                                // o x o
                                // o o o
                                sum += M[i][j+1] + M[i+1][j-1] + M[i+1][j] + M[i+1][j+1];
                                res[i][j] = floor(sum/6);
                            }
                            else {
                                // ----
                                // o x|
                                // o o|
                                sum += M[i+1][j-1] + M[i+1][j];
                                res[i][j] = floor(sum/4);
                            }
                        }
                        else {
                            if (j+1 < col) {
                                // -----
                                // o x o
                                sum += M[i][j+1];
                                res[i][j] = floor(sum/3);
                            }
                            else {
                                // ----
                                // o x|
                                res[i][j] = floor(sum/2);
                            }
                        }
                    }
                }
                else {
                    // not first row
                    if (j == 0) {
                        // first col but not first row
                        if (i+1 < row) {
                            if (j+1 < col) {
                                // 3x2
                                // |o o
                                // |x o
                                // |o o
                                int sum = M[i-1][j] + M[i-1][j+1] + M[i][j] + M[i][j+1] + M[i+1][j] + M[i+1][j+1];
                                res[i][j] = floor(sum/6);
                            }
                            else {
                                // |o|
                                // |x|
                                // |o|
                                int sum = M[i-1][j] + M[i][j] + M[i+1][j];
                                res[i][j] = floor(sum/3);
                            }
                        }
                        else {
                            // last row
                            if (j+1 < col) {
                                // |o o
                                // |x o
                                // ----
                                int sum = M[i-1][j] + M[i-1][j+1] + M[i][j] + M[i][j+1];
                                res[i][j] = floor(sum/4);
                            }
                            else {
                                // |o|
                                // |x|
                                // ----
                                int sum = M[i-1][j] + M[i][j];
                                res[i][j] = floor(sum/2);
                            }
                        }
                    }
                    else {
                        // not first row not first col
                        if (i+1 < row) {
                            if (j+1 < col) {
                                // o o o
                                // o x o
                                // o o o
                                int sum = M[i-1][j-1] + M[i-1][j] + M[i-1][j+1]
                                        + M[i][j-1] + M[i][j] + M[i][j+1]
                                        + M[i+1][j-1] + M[i+1][j] + M[i+1][j+1];
                                res[i][j] = floor(sum/9);
                            }
                            else {
                                // o o|
                                // o x|
                                // o o|
                                int sum = M[i-1][j-1] + M[i-1][j] + M[i][j-1] + M[i][j] + M[i+1][j-1] + M[i+1][j];
                                res[i][j] = floor(sum/6);
                            }
                        }
                        else {
                            if (j+1 < col) {
                                // o o o
                                // o x o
                                // -----
                                int sum = M[i-1][j-1] + M[i-1][j] + M[i-1][j+1] + M[i][j-1] + M[i][j] + M[i][j+1];
                                res[i][j] = floor(sum/6);
                            }
                            else {
                                // o o|
                                // o x|
                                // ----
                                int sum = M[i-1][j-1] + M[i-1][j] + M[i][j-1] + M[i][j];
                                res[i][j] = floor(sum/4);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

// Runtime: 140 ms, faster than 96.40% of C++ online submissions for Image Smoother.
// Memory Usage: 17.7 MB, less than 67.15% of C++ online submissions for Image Smoother.
