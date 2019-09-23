class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        std::transform(A.begin(), A.end(), A.begin(), [](int i) ->int {return i*i;} );
        std::sort(A.begin(), A.end());
        return A;
    }
};
/*Runtime: 116 ms, faster than 50.16% of C++ online submissions for Squares of a Sorted Array.
Memory Usage: 13.3 MB, less than 98.65% of C++ online submissions for Squares of a Sorted Array.*/
