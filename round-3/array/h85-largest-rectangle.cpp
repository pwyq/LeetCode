// I'm superised this problem is hard
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> left(col, 0);
        vector<int> right(col, col);
        vector<int> height(col, 0);
        int res = 0;
        for (int i = 0; i < row; i++) {
            int curr_left = 0;
            int curr_right = col;

            for (int j = 0; j < col; j++) {// records height above (including self)
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], curr_left);
                else {
                    left[j] = 0;
                    curr_left = j+1;
                }
            }
            
            for (int j = col-1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], curr_right);
                else {
                    right[j] = col;
                    curr_right = j;
                }
            }
            
            for (int j = 0; j < col; j++)
                res = max(res, (right[j]-left[j])*height[j]);
        }
        return res;
    }
};

int main() {
    vector<vector<char>> m1 = {{'1','0','1','0','0'},
                               {'1','0','1','1','1'},
                               {'1','1','1','1','1'},
                               {'1','0','0','1','0'}};
    int r1 = Solution().maximalRectangle(m1);
    cout << r1 << endl;
    assert(r1 == 6);
    cout << "==============================================\n";

    vector<vector<char>> m2 = {{'1','1','1','1','1'},
                               {'1','1','0','0','0'},
                               {'1','1','0','0','0'},
                               {'1','1','0','0','0'}};   
    int r2 = Solution().maximalRectangle(m2);
    cout << r2 << endl;
    assert(r2 == 8);
    return 0;
}
