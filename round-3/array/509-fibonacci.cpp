/*
Runtime: 16 ms, faster than 14.93% of C++ online submissions for Fibonacci Number.
Memory Usage: 8.3 MB, less than 83.58% of C++ online submissions for Fibonacci Number.
*/

class Solution {
public:
    int fib(int N) {
        // if (N == 0) {
        //     return 0;
        // }
        // if (N == 1) {
        //     return 1;
        // }
        // return fib(N-1) + fib(N-2);

        // dynamic programming
        if (N < 2) return N;

        int m[N+1];
        m[0] = 0;
        m[1] = 1;
        for (int i = 2; i <= N; i++) {
            m[i] = m[i-1] + m[i-2];
        }
        return m[N];
    }
};
