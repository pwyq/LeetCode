#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& copy) {
        int row = copy.size();
        int col = copy[0].size();
        int res = 0;
        vector<vector<int>> grid;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (copy[i][j] > 0) {
                    grid = copy;
                    res = max(res, maxCost(grid, i, j));
                    grid = copy;
                    res = max(res, maxCost2(grid, i, j));
                    cout << "res = " << res << " for " << i << ", " << j << endl;
                }
            }
        }
        cout << "res=" << res << endl;
        return res;
    }

    int maxCost(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size()) return INT_MIN;
        if (y < 0 || y >= grid[0].size()) return INT_MIN;
        if (grid[x][y] <= 0) return 0;

        int val = grid[x][y];
        grid[x][y] = 0;
        return val + max4(maxCost(grid, x, y-1),
                          maxCost(grid, x+1, y),
                          maxCost(grid, x-1, y),
                          maxCost(grid, x, y+1));
    }

    int maxCost2(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size()) return INT_MIN;
        if (y < 0 || y >= grid[0].size()) return INT_MIN;
        if (grid[x][y] <= 0) return 0;

        int val = grid[x][y];
        grid[x][y] = 0;
        return val + max4(maxCost(grid, x, y+1),
                        maxCost(grid, x, y-1),
        maxCost(grid, x+1, y),
                          maxCost(grid, x-1, y));
    }

    int max4(int a, int b, int c, int d) {
        int e = a > b ? a : b;
        int f = c > d ? c : d;
        return e > f ? e : f;
    }
};

int main() {
    vector<vector<int>> m1 = {{0,6,0},
                             {5,8,7},
                             {0,9,0}};
    int r1 = Solution().getMaximumGold(m1);
    assert(r1==24);
    cout << "---------------------------------------------\n";
    vector<vector<int>> m2 = {{0, 0, 0, 0, 0, 0, 32,0, 0, 20},
                              {0, 0, 2, 0, 0, 0, 0, 40,0, 32},
                              {13,20,36,0, 0, 0, 20,0, 0, 0},
                              {0, 31,27,0, 19,0, 0, 25,18,0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 18,0, 6},
                              {0, 0, 0, 25,0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 21,0, 30,0, 0, 0, 0},
                              {19,10,0, 0, 34,0, 2, 0, 0, 27},
                              {0, 0, 0, 0, 0, 34,0, 0, 0, 0}};
    int r2 = Solution().getMaximumGold(m2);
    cout << r2 << endl;
    assert(r2==129);


    vector<vector<int>> m3 = {{1,0,7,0,0,0},
     {2,0,6,0,1,0},
     {3,5,6,7,4,2},
     {4,3,1,0,2,0},
     {3,0,5,0,20,0}};
    int r3 = Solution().getMaximumGold(m3);
    assert(r3==60);
    return 0;
}