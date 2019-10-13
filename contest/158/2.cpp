class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int g[8][8];
        memset(g,0,sizeof(g));
        for(auto it:queens){
            g[it[0]][it[1]]=1;
        }
        int X[8]={-1,-1,-1,0,0,1,1,1};
        int Y[8]={-1,0,1,-1,1,-1,0,1};
        vector<vector<int>> res;
        for(int i = 0;i<8;i++){
            for(int k = 1;;k++){
                int x=X[i]*k+king[0],y=Y[i]*k+king[1];
                if(x>=0&&x<8&&y>=0&&y<8){
                    if(g[x][y]){
                        res.push_back(vector<int>{x,y});
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};
/*
#include <string>
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

void print_vec(vector<vector<int>> vv) {
    if (vv.size() == 0) return;
    cout << "------------------------\n";
    for (auto v : vv) {
        for (auto i : v)
            cout << i << ", ";
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        sort(queens.begin(), queens.end());
        // 8 directions
        vector<vector<int>> res;
        int row = king[0];
        int col = king[1];

        bool nw = false;
        for (int i = row-1, j = col-1; i >= 0&& j >= 0; i--, j--) {
            for (int k = 0; k < queens.size(); k++) {
                if (queens[k][0] == i && queens[k][1] == j) {
                    res.push_back({i, j});
                    nw = true;
                    break;
                }
            }
            if (nw) break;
        }

        bool se = false;
        for (int i = row+1, j = col+1; i < 8 && j < 8; i++, j++) {
            for (int k = 0; k < queens.size(); k++) {
                if (queens[k][0] == i && queens[k][1] == j) {
                    res.push_back({i, j});
                    se = true;
                    break;
                }
            }
            if (se) break;
        }


        bool ne = false;
        for (int i = row-1, j = col+1; i >= 0 && j < 8; i--, j++) {
            for (int k = 0; k < queens.size(); k++) {
                if (queens[k][0] == i && queens[k][1] == j) {
                    res.push_back({i, j});
                    ne = true;
                    break;
                }
            }
            if (ne) break;
        }

        bool sw = false;
        for (int i = row+1, j = col-1; i < 8 && j >= 0; i++, j--) {
            for (int k = 0; k < queens.size(); k++) {
                if (queens[k][0] == i && queens[k][1] == j) {
                    res.push_back({i, j});
                    sw = true;
                    break;
                }
            }
            if (sw) break;
        }

        bool nn = false;
        for (int i = row-1, j = col; i >= 0; i--) {
            for (int k = 0; k < queens.size(); k++) {
                if (queens[k][0] == i && queens[k][1] == j) {
                    res.push_back({i, j});
                    nn = true;
                    break;
                }
            }
            if (nn) break;
        }

        bool ss = false;
        for (int i = row+1, j = col; i < 8; i++) {
            for (int k = 0; k < queens.size(); k++) {
                if (queens[k][0] == i && queens[k][1] == j) {
                    res.push_back({i, j});
                    ss = true;
                    break;
                }
            }
            if (ss) break;
        }

        bool ww = false;
        for (int i = row, j = col-1; j >= 0; j--) {
            for (int k = 0; k < queens.size(); k++) {
                if (queens[k][0] == i && queens[k][1] == j) {
                    res.push_back({i, j});
                    ww = true;
                    break;
                }
            }
            if (ww) break;
        }

        bool ee = false;
        for (int i = row, j = col+1; j < 8; j++) {
            for (int k = 0; k < queens.size(); k++) {
                if (queens[k][0] == i && queens[k][1] == j) {
                    res.push_back({i, j});
                    ee = true;
                    break;
                }
            }
            if (ee) break;
        }

        return res;
    }
};

int main() {
    vector<vector<int>> q1 = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
    vector<int> k1 = {0,0};
    vector<vector<int>> r1 = Solution().queensAttacktheKing(q1, k1);

    cout << "---------------2\n";

    vector<vector<int>> q2 = {{2,4},{1,5}, {5,1}, {6,0},{2,2},{1,1}};
    vector<int> k2 = {3,3};
    vector<vector<int>> r2 = Solution().queensAttacktheKing(q2, k2);
    cout << "---------------3\n";

    vector<vector<int>> q3 = {{6,6},{5,5}, {6,4}, {5,4}};
    vector<int> k3 = {4,4};
    vector<vector<int>> r3 = Solution().queensAttacktheKing(q3, k3);
    cout << "---------------4\n";

    vector<vector<int>> q4 = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};
    vector<int> k4 = {3,4};
    vector<vector<int>> r4 = Solution().queensAttacktheKing(q4, k4);
    return 0;

}
*/