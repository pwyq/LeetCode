class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // intuition: Kadane's algorithm, using difference
        // LOL, this is exactly the same as 3rd solution (simple one pass)
        int total = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) {
                total += diff;
            }
        }
        return total;
    }
};

// lol, didn't expect to pass on first try thou
// Runtime: 4 ms, faster than 99.42% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 9.6 MB, less than 29.42% of C++ online submissions for Best Time to Buy and Sell Stock II.
