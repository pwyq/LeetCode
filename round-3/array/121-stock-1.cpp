class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l_min = INT_MAX;
        int r_max = 0;
        
        vector<int> buys;
        vector<int> sells;
        for (int i = 0, j = prices.size()-1; i < prices.size() && j >= 0; i++, j--) {
            if (l_min > prices[i]) {
                l_min = prices[i];
            }
            if (r_max < prices[i]); {
                r_max = prices[i];
            }
            
            buys.push_back(l_min);
            sells.push_back(r_max);
        }
        
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            res = max(sells[i] - buys[i], res);
        }
        return res;
    }
};

/* Runtime: 4 ms, faster than 98.20% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 10.1 MB, less than 5.51% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
