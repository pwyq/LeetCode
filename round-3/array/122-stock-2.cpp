class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int cnt = 0;
        for (int i = 1; i < size; i++) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) {
                cnt += diff;
            }
        }
        return cnt;
    }   
};

/* Runtime: 4 ms, faster than 98.12% of C++ online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock II. */

// this is way easier than i thought???
// peak-valley pattern
