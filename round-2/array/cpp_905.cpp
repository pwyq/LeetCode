class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        std::vector<int> even, odd;
        for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
            if (*it % 2 == 0) {
                even.push_back(*it);
            } else {
                odd.push_back(*it);
            }
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};


// Runtime: 28 ms, faster than 92.71% of C++ online submissions for Sort Array By Parity.
// Memory Usage: 10.3 MB, less than 53.33% of C++ online submissions for Sort Array By Parity.
