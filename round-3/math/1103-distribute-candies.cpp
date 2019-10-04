// Lessons:
// when doing division, always make sure there is no overflow(?)
// e.g even-num/2, make sure the numerator is always even, otherwise 5/2 = 2

/* Alternatively, 100%, 100%, thanks dalao
Time: O(sqrt(candies))

class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res(n);
        for (int i = 0; candies > 0; ++i) {
            res[i % n] += min(candies, i + 1);
            candies -= i + 1;
        }
        return res;
    }
};

*/
class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res(n, 0);
        
        int m = 1; // 1-based iteration count
        int sum = 0;
        while (candies >= 0) {                      // O(sqrt(candies))
            int sq = pow(n, 2);
            int curr = (m-1)*sq + (sq+n)/2;
            candies -= curr;
            if (candies < 0)  {
                candies += curr;
                break;
            }
            m++;    // iteration++
        }
        
        // for each person, this is for whole run, column-wise candy sum
        if (m > 1) {
            int t = m-1;
            int first_term = ((t-1) * t * n)/2; // guarantee always be even-num/2
            for (int i = 0; i < n; i++) {           // O(n)
                res[i] += first_term + (t*(i+1));
            }
        }
        
        int start_term = (m-1)*n+1;
        int p = 0;
        while (candies >= 0) {                      // O(n) worse case
            candies -= start_term;
            if (candies < 0) {
                candies += start_term;
                res[p] += candies;
                break;
            }
            res[p++] += start_term;
            start_term++;
        }
        return res;
    }
};

// Runtime: 4 ms, faster than 64.55% of C++ online submissions for Distribute Candies to People.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Distribute Candies to People.
