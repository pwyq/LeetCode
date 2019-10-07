// Number Theory
// OMG
// Thanks Fermat
class Solution {
public:
    bool judgeSquareSum(int c) {
// Fermat Theorem: Any positive number n is expressible as a sum of two squares if and only if the prime factorization of n, every prime of the form (4k+3) occurs an even number of times.
        for (int i = 2; i * i <= c; i++) {
            int count = 0;
            if (c % i == 0) {
                while (c % i == 0) {
                    count++;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;  // if equal, means that the (c) only occured once, violating the fermat theorem
    }
};
