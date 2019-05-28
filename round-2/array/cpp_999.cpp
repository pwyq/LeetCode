class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // loop through the board
        // record all Pawn's and Rook's position
        // then start matching...
        vector<pair<int, int>> Pawn;
        vector<pair<int, int>> Bishop;
        pair<int, int> Rook;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'p') {
                    Pawn.push_back(std::make_pair(i, j));
                }
                else if (board[i][j] == 'B') {
                    Bishop.push_back(std::make_pair(i, j));
                }
                else if (board[i][j] == 'R') {
                    Rook = std::make_pair(i, j);
                }
            }
        }
        
        int count = 0;
        int maxNorth = -1;
        int minEast = 8;
        int maxWest = -1;
        int minSouth = 8;
        for (int i = 0; i < Pawn.size(); i++) {
            if (Pawn[i].first == Rook.first) {
                if (Pawn[i].second < Rook.second && Pawn[i].second > maxWest) {
                    if (maxWest == -1) {
                        count++;
                    }
                    maxWest = Pawn[i].second;
                }
                else if (Pawn[i].second > Rook.second && Pawn[i].second < minEast) {
                    if (minEast == 8) {
                      count++;                      
                    }
                    minEast = Pawn[i].second;
                }
            }
            else if (Pawn[i].second == Rook.second) {
                if (Pawn[i].first < Rook.first && Pawn[i].first > maxNorth) {
                    if (maxNorth == -1) {
                        count++;                   
                    }
                    maxNorth = Pawn[i].first;
                }
                else if (Pawn[i].first > Rook.first && Pawn[i].first < minSouth) {
                    if (minSouth == 8) {
                        count++;
                    }
                    minSouth = Pawn[i].first;
                }
            }
        }

        // Note: bool A, B = true; -> A = false, B = true
        bool lockW = true;
        bool lockE = true;
        bool lockN = true;
        bool lockS = true;
        for (int i = 0; i < Bishop.size(); i++) {
            if (Bishop[i].first == Rook.first) {
                if (Bishop[i].second < Rook.second && maxWest != -1 && Bishop[i].second > maxWest && lockW) {
                    count--;
                    lockW = false;
                }
                else if (Bishop[i].second > Rook.second && minEast != 8 && Bishop[i].second < minEast && lockE) {
                    count--;
                    lockE = false;
                }
            }
            if (Bishop[i].second == Rook.second) {
                if (Bishop[i].first < Rook.first && maxNorth != -1 && Bishop[i].first > maxNorth && lockN) {
                    count--;
                    lockN = false;
                }
                else if (Bishop[i].first > Rook.first && minSouth != 8 && Bishop[i].first < minSouth && lockS) {
                    count--;
                    lockS = false;
                }
            }
        }
        
        return count;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Available Captures for Rook.
// Memory Usage: 8.5 MB, less than 74.41% of C++ online submissions for Available Captures for Rook.
