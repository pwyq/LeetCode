class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int ma = INT_MIN;
        int mi = INT_MAX;
        for (int i : A) {
            if (ma < i)
                ma = i;
            if (mi > i)
                mi = i;
        }
        
        ma -= K;
        mi += K;
        if (ma > mi)
            return ma-mi;
        return 0;
    }
};
Runtime: 20 ms, faster than 86.02% of C++ online submissions for Smallest Range I.
Memory Usage: 9.6 MB, less than 87.50% of C++ online submissions for Smallest Range I.
