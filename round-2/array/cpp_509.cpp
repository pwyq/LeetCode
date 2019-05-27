class Solution {
public:
    int fib(int N) {
        // recursive
        // if (N == 0) {
        //     return 0;
        // }
        // if (N == 1) {
        //     return 1;
        // }
        // return fib(N-1)+fib(N-2);
        
        
        // Runtime: 16 ms, faster than 22.66% of C++ online submissions for Fibonacci Number.
        // Memory Usage: 8.2 MB, less than 67.60% of C++ online submissions for Fibonacci Number.
        
        // dynamic programming
        if(N < 2)
            return N;
        int memo[N+1];
        memo[0] = 0;
        memo[1] = 1;
        for(int i=2; i<=N; i++)
            memo[i] = memo[i-1] + memo[i-2];
        return memo[N];
    
        // Runtime: 4 ms, faster than 94.05% of C++ online submissions for Fibonacci Number.
        // Memory Usage: 8.4 MB, less than 33.79% of C++ online submissions for Fibonacci Number.

    }
};
