class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> even;
        vector<int> odd;
        
        for (int &i : A) {
            if (i % 2 == 0) {
                even.push_back(i);
            }
            else {
                odd.push_back(i);
            }
        }
        
        vector<int> res;
        for (int i = 0; i < A.size(); i++) {
            if (i % 2 == 0) {
                res.push_back(even.back());
                even.pop_back();
            }
            else {
                res.push_back(odd.back());
                odd.pop_back();
            }
        }
        return res;
        
    }
};

// slower than round-2
/*
 * Runtime: 88 ms, faster than 30.55% of C++ online submissions for Sort Array By Parity II.
Memory Usage: 14.4 MB, less than 6.25% of C++ online submissions for Sort Array By Parity II.*/
