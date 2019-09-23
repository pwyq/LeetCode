class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // find the coord the Rook, then iter thru 4 directions
        
        int row = -1;
        int col = -1;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R') {
                    row = i;
                    col = j;
                }
            }
        }
        int res = 0;
        for (int i = row-1; i >= 0; i--) {
            if (board[i][col] == 'p') {
                res++;
                break;
            }
            else if (board[i][col] == 'B') {
                break;
            }
        }
        for (int i = row+1; i <= 7; i++) {
            if (board[i][col] == 'p') {
                res++;
                break;
            }
            else if (board[i][col] == 'B') {
                break;
            }
        }
        
        for (int i = col-1; i >= 0; i--) {
            if (board[row][i] == 'p') {
                res++;
                break;
            }
            else if (board[row][i] == 'B') {
                break;
            }
        }
        for (int i = col+1; i <= 7; i++) {
            if (board[row][i] == 'p') {
                res++;
                break;
            }
            else if (board[row][i] == 'B') {
                break;
            }
        }
        return res;
    }
};
// Significantly clearer and straightfoward than last submission!

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Available Captures for Rook.
Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Available Captures for Rook.*/
