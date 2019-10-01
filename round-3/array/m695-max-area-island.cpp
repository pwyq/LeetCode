#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

void print_vec(vector<vector<int>> grid) {
    for (auto r : grid) {
        for (auto c : r)
            cout << c << " ";
        cout << endl;
    }
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // TOO many edge cases for this one
        // loop thru 2D array
        // check left and up cells,
        // if there is a mark and current cell is 1, added their value to current cell
        // use a counter to update the max
        
        // Use BFS or DFS

        return max_island;
    }

    int recursive(vector<vector<int>>& grid, int row, int col, int x, int y, int n) {
        int north = (y-1 > 0) ? grid[x][y-1] : 0;
        int south = (y+1 < col) ? grid[x][y+1] : 0;
        int west  = (x-1 > 0) ? grid[x-1][y] : 0;
        int east  = (x+1 < row) ? grid[x+1][y] : 0;
    }
};

int main() {

    vector<vector<int> > v2{ {0,0,1,0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
                             {1,1,0,0,1,1,0,0,1,0,1,0,0},
                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    print_vec(v2);
    cout << "------------------\n";
    int r2 = Solution().maxAreaOfIsland(v2);
    assert(r2== 6);
    cout << "==================\n";

    vector<vector<int>> v3{{0,0,0,0,0,0,0,0}};
    cout << "------------------\n";
    int r3 = Solution().maxAreaOfIsland(v3);
    assert(r3 == 0);
    cout << "==================\n";

    vector<vector<int> > v1{{1,1,0,0,0}, 
                            {1,1,0,0,0}, 
                            {0,0,0,1,1},
                            {0,0,0,1,1}};
    print_vec(v1);
    cout << "------------------\n";
    int r1 = Solution().maxAreaOfIsland(v1);
    assert(r1 == 4);
    cout << "==================\n";
    return 0;
}
