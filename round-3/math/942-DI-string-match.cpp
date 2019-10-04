class Solution {
public:
    vector<int> diStringMatch(string S) {
        // order 0 to N, nums
        // if I, take the min from unused nums
            // for second I, take the next min (min+1) from unused nums
        // if D, take the max from unused nums
            // for second D, take the next max (max-1) from unused nums
        
        int mi = 0;
        int ma = S.length();
        vector<int> res;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'I') {
                res.push_back(mi++);
            }
            else {
                res.push_back(ma--);
            }
        }

        if (ma == S.length()) {
            res.push_back(ma);
            return res;
        }
        res.push_back(mi);
        return res;
    }
};

// Runtime: 52 ms, faster than 8.45% of C++ online submissions for DI String Match.
// Memory Usage: 10.4 MB, less than 42.86% of C++ online submissions for DI String Match.

// Runtime: 40 ms, faster than 70.31% of C++ online submissions for DI String Match.
// Memory Usage: 10.5 MB, less than 7.14% of C++ online submissions for DI String Match.
