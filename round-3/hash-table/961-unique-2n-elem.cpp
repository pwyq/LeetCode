// ~4min

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> m;

        int n = A.size() / 2;
        int res = -1;
        for (int i : A) {
            if (++m[i] == n) {
                res = i;
                break;
            }
        }
        return res;
    }
};
