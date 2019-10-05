class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // we only care the bottom right corner index
        for (auto x : ops) {
            m = min(m, x[0]);
            n = min(n, x[1]);
        }
        return m*n;
    }
};
