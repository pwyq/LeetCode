#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <deque>    // double-ended queue
using namespace std;

// thanks dalao

template <class myClass>
void print_vec(vector<vector<myClass>> grid) {
    for (auto r : grid) {
        for (auto c : r)
            cout << c << " ";
        cout << endl;
    }
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        // print_vec(visited);
        int area = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    area = max(area, DFS(grid, visited, i, j));
                    // area = max(area, BFS(grid, visited, i, j));
                }
            }
        }

        cout << "area = " << area << endl;
        return area;
    }

    int DFS(vector<vector<int>>& grid, vector<vector<bool>>& visit, int x, int y) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && visit[x][y] == false && grid[x][y] == 1) {
            visit[x][y] = true;
            int north = DFS(grid, visit, x-1, y);
            int south = DFS(grid, visit, x+1, y);
            int west  = DFS(grid, visit, x, y-1);
            int east  = DFS(grid, visit, x, y+1);
            return 1 + north + south + west + east;
        }
        return 0;
    }

    int BFS(vector<vector<int>>& grid, vector<vector<bool>>& visit, int x, int y) {
        if (grid[x][y] == 0 || visit[x][y] == true)
            return 0;

        int row = grid.size();
        int col = grid[0].size();
        visit[x][y] = true;
        deque<vector<int>> q;
        int res = 1;
        q.push_back({x,y});
        while (q.empty() == false) {
            auto p = q.front();
            q.pop_front();
            int m = p[0]-1;
            int n = p[1];
            if (m >= 0 && m < row && n >= 0 && n < col && grid[m][n] == 1 && visit[m][n] == false) {
                res++;
                visit[m][n] = true;
                q.push_back({m,n});
            }
            m = p[0]+1;
            if (m >= 0 && m < row && n >= 0 && n < col && grid[m][n] == 1 && visit[m][n] == false) {
                res++;
                visit[m][n] = true;
                q.push_back({m,n});
            }
            m = p[0];
            n = p[1]-1;
            if (m >= 0 && m < row && n >= 0 && n < col && grid[m][n] == 1 && visit[m][n] == false) {
                res++;
                visit[m][n] = true;
                q.push_back({m,n});
            }
            n = p[1]+1;
            if (m >= 0 && m < row && n >= 0 && n < col && grid[m][n] == 1 && visit[m][n] == false) {
                res++;
                visit[m][n] = true;
                q.push_back({m,n});
            }
        }
        return res;
    }
};

int main() {

    vector<vector<int> > v1{{1,1,0,0,0}, 
                            {1,1,0,0,0}, 
                            {0,0,0,1,1},
                            {0,0,0,1,1}};
    print_vec(v1);
    cout << "------------------\n";
    int r1 = Solution().maxAreaOfIsland(v1);
    assert(r1 == 4);
    cout << "==================\n";

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


    vector<vector<int>> v4{{1}};
    print_vec(v4);
    cout << "------------------\n";
    int r4 = Solution().maxAreaOfIsland(v4);
    assert(r4 == 1);
    cout << "==================\n";


    return 0;
}
