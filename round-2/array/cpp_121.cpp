class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // intuition: O(n) brute force
        // if (!prices.size()) return 0;
        // int buy = prices[0];
        // int buyDay = 0;
        // int sell = -1;
        // int sellDay = -1;
        // int res = 0;
        // for (int i = 1; i < prices.size(); i++) {
        //     if (buy > prices[i]) {
        //         buy = prices[i];
        //         buyDay = i;
        //     }
        //     else if (sell <= prices[i]) {
        //         sell = prices[i];
        //         sellDay = i;
        //     }
        //     int diff = sell - buy;
        //     if (buyDay < sellDay && res < diff) {
        //         res = diff;
        //     }
        //     if (prices[i] - buy > res) {
        //         sell = prices[i];
        //         sellDay = i;
        //         res = prices[i] - buy;
        //     }
        //     cout << "buy = " << buy << " at day " << buyDay << ", sell = " << sell << " at day " << sellDay << endl;
        // }
        // return res;
        
        // O(n^2) brute force
        // int res = 0;
        // for (int i = 0; i < prices.size(); i++) {
        //     for (int j = i+1; j < prices.size(); j++) {
        //         int profit = prices[j] - prices[i];
        //         if (profit > res) {
        //             res = profit;
        //         }
        //     }
        // }
        // return res;
// Runtime: 852 ms, faster than 6.21% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 9.7 MB, less than 8.30% of C++ online submissions for Best Time to Buy and Sell Stock.

        // One Pass (my first intution is like this)
        // int buy = INT_MAX;
        // int profit = 0;
        // for (int i = 0; i < prices.size(); i++) {
        //     if (buy > prices[i]) {
        //         buy = prices[i];
        //     }
        //     else if (prices[i] - buy > profit) {
        //         profit = prices[i] - buy;
        //     }
        // }
        // return profit;
// Runtime: 8 ms, faster than 91.17% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 9.5 MB, less than 46.78% of C++ online submissions for Best Time to Buy and Sell Stock.
        
        // one pass
        int minPrice = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i]-minPrice);
        }
        return profit;
        
// Runtime: 8 ms, faster than 90.85% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 9.7 MB, less than 6.62% of C++ online submissions for Best Time to Buy and Sell Stock.
    }
};

// 5 submit...
// Runtime: 40 ms, faster than 13.25% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 9.7 MB, less than 7.51% of C++ online submissions for Best Time to Buy and Sell Stock.
