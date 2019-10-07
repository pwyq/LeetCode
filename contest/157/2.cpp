#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            
        }
    }
};

/*
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, 1);
        map<int, int> best_map;

        for (int i = 0; i < n; i++) {
            int goal = arr[i] - difference;

            if (best_map.find(goal) != best_map.end())
                dp[i] = max(dp[i], best_map[goal] + 1);

            best_map[arr[i]] = max(best_map[arr[i]], dp[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
*/
