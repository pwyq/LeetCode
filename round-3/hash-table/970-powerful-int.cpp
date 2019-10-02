class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        // brute force
        // thanks dalao for this neat soln
        unordered_set<int> res;
        for (int i = 1; i <= bound; i*= x) {
            for (int j = 1; i+j <= bound; j *= y) {
                res.insert(i+j);
                if (y == 1) break;  // inf loop
            }
            if (x == 1) break;  // inf loop
        }
        return vector<int>(res.begin(), res.end());
    }
};
