class Solution {
public:
    
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        int res = 0;
        for (int t : time) {
            res += cnt[(600-t) % 60];         // using complement, 600 is for corner case 0 and 60, and it's above 500-limit from the Question
            cnt[t % 60]++;
        }
        return res;
    }
    
    /* This theoretically works, but doing large factorial requires long bit which fails the idea.
    int numPairsDivisibleBy60(vector<int>& time) {
        // modify hint 2
        // 1. module every song, store in a hashmap of size 60
        // 2. for 30, use n choose 2 formula
        // 3. for others, count complemnt pairs

        vector<int> lengths(60, 0);
        for (int & i : time) {
            lengths[i%60]++;
        }

        int res = 0;
        for (int i = 0; i <=30; i++) {
            if (i == 30 || i == 0) {
                res += my_n_choose_two(lengths[i]);
            }
            else {
                res += lengths[i] * lengths[60-i];
            }
        }
        return res;
    }

    int my_n_choose_two(int n) {
        if (n == 0 || n == 1) return 0;
        if (n == 2) return 1;
        int numerator = my_factorial(n);
        int denominator = 2 * my_factorial(n-2);
        int result = (int) (numerator / denominator);
        return result;
    }

    int my_factorial(int n) { 
        return (n==1 || n==0) ? 1: n * my_factorial(n - 1);  
    }
    */
};

/* Thanks to dalao, this question took me 1hour+
 * Runtime: 32 ms, faster than 94.03% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.*/
