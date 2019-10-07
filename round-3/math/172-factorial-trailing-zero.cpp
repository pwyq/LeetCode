// thanks dalao
class Solution {
public:
    // only number 2 and 5 could result in 10, which is one zero
    // so we have to find the number of pair of (2,5)
    // since # of 2 >> # of 5 (such as 4 = 2*2)
    // we only have to find the # of 5
    int trailingZeroes(int n) {
        if (n < 5) return 0;
        return n/5 + trailingZeroes(n/5);
    }
};
