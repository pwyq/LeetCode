class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &row : A) {
            // http://www.cplusplus.com/reference/algorithm/reverse/
            // std::reverse
            reverse(row.begin(), row.end());
        }
        for (auto &row : A) {
            for (int &col : row) {
                col ^= 1;   // exclusive or, when bit differs, it gives a 1; when bits are the same, it gives a 0
            }
        }
        return A;
    }
};
/*
 * Runtime: 12 ms, faster than 70.22% of C++ online submissions for Flipping an Image.
Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Flipping an Image.*/
