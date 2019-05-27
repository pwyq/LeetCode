class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // for (auto& i : A) i *= i;
        // sort(A.begin(), A.end());
        // return A;
        // Runtime: 116 ms, faster than 59.41% of C++ online submissions for Squares of a Sorted Array.
        // Memory Usage: 13.6 MB, less than 75.80% of C++ online submissions for Squares of a Sorted Array.
        
        int n = A.size();
        vector<int> res(n);  // initialize vector with size
        int i = 0, j = n - 1;
        for (int p = n - 1; p >= 0; p--) {
            if (abs(A[i]) > abs(A[j])) {
                res[p] = A[i] * A[i];
                i++;
            }
            else {
                res[p] = A[j] * A[j];
                j--;
            }
        }
        return res;
        
        // Runtime: 92 ms, faster than 98.74% of C++ online submissions for Squares of a Sorted Array.
        // Memory Usage: 13.4 MB, less than 82.41% of C++ online submissions for Squares of a Sorted Array.
    }
};
