class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        // thanks dalao for the intuition; total area - overlapping area
        // tower area = 4*size + 2
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0)
                    res += grid[i][j]*4 + 2;
                if (i != 0)
                    res -= min(grid[i][j], grid[i-1][j])*2;
                if (j != 0)
                    res -= min(grid[i][j], grid[i][j-1])*2;
            }
        }
        return res;
    }
};
