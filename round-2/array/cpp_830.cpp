class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        for (int i = 0; i < S.size(); i++) {
            int start = i;
            while (S[i] == S[i+1]) {
                i++;
            }
            if ((i-start) >= 2) {
                res.push_back({start, i});
            }
        }
        return res;
    }
};

// Runtime: 8 ms, faster than 91.03% of C++ online submissions for Positions of Large Groups.
// Memory Usage: 9.5 MB, less than 53.63% of C++ online submissions for Positions of Large Groups.
