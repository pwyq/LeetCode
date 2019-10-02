class Solution {
public:
    int countPrimes(int n) {
        // animation to illustrate the algorithm
        // https://assets.leetcode.com/static_assets/public/images/solutions/Sieve_of_Eratosthenes_animation.gif
        // thanks dalao
        if (n <= 1) return 0;
        vector<bool> not_primes(n, 0);
        
        not_primes[0] = true;
        not_primes[1] = true;
        for (int i = 2; i < sqrt(n); i++) {
            if (not_primes[i] == false) {
                for (int j = 2; i*j < n; j++) {
                    not_primes[i*j] = true;
                }
            }
        }
        int count = 0;
        for (int i : not_primes) {
            if (i == 0)
                count++;
        }
        return count;
    }
};
