class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 1000...0     0111...1
        return n > 0 && ((n & (n-1)) == 0);
    }
};

/*
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n > 1) {
            if (n % 3 != 0) {
                return false;
            }
            n = n / 3;
        }
        return true;
    }
*/
