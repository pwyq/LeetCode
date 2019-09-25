// I. brute force
    /*
    a b c
    d e f
    g h k
    */
// optimization:
// observe that, x1+x2+x3 = 1+...+9 = 45 = y1+y2+y3 => x1 = ... = y3 = 15 = d1 = d2
// x2 + y2 + d1 + d2 = 60 = a + ... + k + (e*3) = 45 + 3e ===> e = 5
// so for a magic square, e must be 5

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Magic Squares In Grid.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Magic Squares In Grid.
// https://leetcode.com/problems/magic-squares-in-grid/discuss/133874/Python-5-and-43816729
// check wiki for magic-square for more interesting stuff (it's long thou)

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n < 2 || m < 2) return 0;
        
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++) {
                int e = grid[i-1][j-1];
                if (e < 1 || e > 9 || e != 5)
                    continue;
                
                int a = grid[i-2][j-2];
                if (a < 1 || a > 9)
                    continue;
                int b = grid[i-2][j-1];
                if (b < 1 || b > 9)
                    continue;
                int c = grid[i-2][j];
                if (c < 1 || c > 9)
                    continue;
                int d = grid[i-1][j-2];
                if (d < 1 || d > 9)
                    continue;
                int f = grid[i-1][j];
                if (f < 1 || f > 9)
                    continue;
                int g = grid[i][j-2];
                if (g < 1 || g > 9)
                    continue;
                int h = grid[i][j-1];
                if (h < 1 || h > 9)
                    continue;
                int k = grid[i][j];
                if (k < 1 || k > 9)
                    continue;
                
                if (a == b || b == c || c == d || d == e || e == f || f == g || g == h || h == k)
                    continue;
                
                int x1 = a + b + c;
                int x2 = d + e + f;
                int x3 = g + h + k;
                int y1 = a + d + g;
                int y2 = b + e + h;
                int y3 = c + f + k;
                int d1 = a + e + k;
                int d2 = c + e + g;
                if (x1 == x2 && x2 == x3 &&
                    x3 == y1 && y1 == y2 &&
                    y2 == y3 && y3 == d1 &&
                    d1 == d2)
                {
                    cnt++;
                }
                // else {
                //     cout << x1 << ", " << x2 << ", " << x3 << ", "
                //          << y1 << ", " << y2 << ", " << y3 << ", "
                //          << d1 << ", " << d2 << endl;
                // }
            }
        }
        return cnt;
    }
};
