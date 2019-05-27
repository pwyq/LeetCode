class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even = 0, odd = 1;
        vector<int> res = A;    // notes: need to initialize values for vector res
        for (auto i : A) {
            if (i % 2 == 0) {
                res[even] = i;
                even +=2;
            }
            else {
                res[odd] = i;
                odd += 2;
            }
        }
        return res;
        
        // Runtime: 84 ms, faster than 92.03% of C++ online submissions for Sort Array By Parity II.
        // Memory Usage: 11.8 MB, less than 73.34% of C++ online submissions for Sort Array By Parity II.
    }
};
