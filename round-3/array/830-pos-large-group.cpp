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

// Thanks to my own post 4 months ago (receives 2 upvotes lol)
