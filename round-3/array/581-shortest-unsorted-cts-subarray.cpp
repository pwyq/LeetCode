// Tried 5 times... wasted a lot of time on trying traditional l-r scan and offset stuff...
// Saw one title (accidentally) soln contains "sort", and I came up with following, pass one time...

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;

        std::sort(copy.begin(), copy.end());

        int n = nums.size();
        int l = 0;
        for (; l < n; l++) {
            if (nums[l] != copy[l]) {
                break;
            }
        }
        if (l == n) return 0;

        int r = n-1;
        for (; r >= 0; r--) {
            if (nums[r] != copy[r]) {
                break;
            }
        }
        cout << l << ", " << r << endl;
        return (r-l+1);
    }
};
// Runtime: 44 ms, faster than 47.11% of C++ online submissions for Shortest Unsorted Continuous Subarray.
// Memory Usage: 11.3 MB, less than 42.86% of C++ online submissions for Shortest Unsorted Continuous Subarray.

// thanks to dalao
        // MAX-MIN vectors
        int n = nums.size();
        vector<int> maxlhs(n);   // max number from left to cur
        vector<int> minrhs(n);   // min number from right to cur
        for (int i = n - 1, minr = INT_MAX; i >= 0; i--) minrhs[i] = minr = min(minr, nums[i]);
        for (int i = 0,     maxl = INT_MIN; i < n;  i++) maxlhs[i] = maxl = max(maxl, nums[i]);

        int i = 0, j = n - 1;
        while (i < n && nums[i] <= minrhs[i]) i++;
        while (j > i && nums[j] >= maxlhs[j]) j--;

        return j + 1 - i;
        
// Runtime: 32 ms, faster than 93.41% of C++ online submissions for Shortest Unsorted Continuous Subarray.
// Memory Usage: 11.8 MB, less than 19.05% of C++ online submissions for Shortest Unsorted Continuous Subarray.
