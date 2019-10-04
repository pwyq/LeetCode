// thanks dalao for the insight
// I could solve, but certainly with a more complex approach
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        // For a sorted A:
        // If A[n-1] >= A[n-2] + A[n-3] >= A[i] + A[j], where 0 < j < i < n-1 we cannot get any triangle with A[n-1]
        // so it's safe to skip A[n-1]
        for (int i = A.size() - 1 ; i > 1; --i)
            if (A[i] < A[i - 1] + A[i - 2])
                return A[i] + A[i - 1] + A[i - 2];
        return 0;
    }
};
