class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // sort and compare?
        // std::sort uses quick-sort with avg O(nlogn)
        vector<int> res = heights;
        sort(heights.begin(), heights.end());
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (res[i] != heights[i]) {
                count++;
            }
        }
        return count;
        // Runtime: 8 ms, faster than 65.76% of C++ online submissions for Height Checker.
        // Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Height Checker.
    }
};
