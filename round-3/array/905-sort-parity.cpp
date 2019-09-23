class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        int even_idx = 0;
        for (auto i = A.begin(); i != A.end(); i++) {
            if (*i % 2 == 0) {
                res.insert(res.begin()+even_idx, *i);
                even_idx++;
            }
            else {
                res.push_back(*i);
            }
        }
        return res;
        // On last run, I did was using two vectors (1 odd, 1 even), then concatenate, which saves inserting cost
    }
};

/*
 * Runtime: 60 ms, faster than 9.34% of C++ online submissions for Sort Array By Parity.
Memory Usage: 10 MB, less than 31.04% of C++ online submissions for Sort Array By Parity.*/
