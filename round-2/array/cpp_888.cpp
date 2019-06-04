class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        // std::accumulate(first, end, init)
        int diff = (accumulate(B.begin(), B.end(), 0) - accumulate(A.begin(), A.end(), 0)) / 2;
        // A - x + y = B + x - y
        // (B-A)/2 + x = y
        unordered_set<int> Y(B.begin(), B.end());
        for (int x: A)
            if (Y.count(x + diff))
                return {x, x+diff};
        return {0, 0};
    }
};

// Runtime: 112 ms, faster than 86.42% of C++ online submissions for Fair Candy Swap.
// Memory Usage: 20 MB, less than 53.43% of C++ online submissions for Fair Candy Swap.
