/*Runtime: 8 ms, faster than 63.43% of C++ online submissions for Height Checker.
Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Height Checker.*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy = heights;
        std::sort(heights.begin(), heights.end());

        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
           if (heights[i] != copy[i]) res++;
        }
        return res;
    }
};
