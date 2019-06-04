class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() == 1) return true;
        bool isIncreasing = false;
        for (int i = 1; i < A.size(); i++) {
            if (A[i-1] != A[i]) {
                isIncreasing = A[i-1] < A[i] ? true : false;
                break;
            }
        }
        if (isIncreasing) {
            for (int i = 1; i < A.size(); i++) {
                if (A[i-1] > A[i]) {
                    return false;
                }
            }
        }
        else {
            for (int i = 1; i < A.size(); i++) {
                if (A[i-1] < A[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

// Runtime: 80 ms, faster than 90.15% of C++ online submissions for Monotonic Array.
// Memory Usage: 14.2 MB, less than 46.52% of C++ online submissions for Monotonic Array.
