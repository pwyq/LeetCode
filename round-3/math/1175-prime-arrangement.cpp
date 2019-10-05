class Solution {
public:
    // constexpr static auto MOD = static_cast<int>(1e9+7);
    int numPrimeArrangements(int n) {
        const unsigned int MOD = 1000000007;  // often used in programming competitions https://www.geeksforgeeks.org/modulo-1097-1000000007/
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        int num_primes = 0;
        for (int i = 1; i <= min(97, n); i++)
            if (i == primes[num_primes])
                num_primes++;
        long long res = 1;
        for (int i = 1; i <= num_primes; i++)
            res = res * i % MOD;
        for (int i = 1; i <= n-num_primes; i++)
            res = res * i % MOD;
        return res;
    }
};

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Prime Arrangements.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Prime Arrangements.