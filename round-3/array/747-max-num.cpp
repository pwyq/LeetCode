class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        vector<int> maxs(2,-1);
        int idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            // cout << i << ", " << maxs[0] << ", " << maxs[1] << endl;
            if (nums[i] > maxs[0]) {
                maxs[1] = maxs[0];
                maxs[0] = nums[i];
                idx = i;
            }
            else if (nums[i] > maxs[1]) {
                maxs[1] = nums[i];
            }
        }
        return (maxs[0] >= 2*maxs[1]) ? idx : -1;
    }
};

/*
Runtime: 4 ms, faster than 65.59% of C++ online submissions for Largest Number At Least Twice of Others.
Memory Usage: 8.4 MB, less than 90.00% of C++ online submissions for Largest Number At Least Twice of Others.
*/
