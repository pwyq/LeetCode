class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Sorting time: O(n*logn)
        
        // std::sort(nums.begin(), nums.end());
        // int n = (int)nums.size();
        // int temp = -1000;
        // if (nums[0] < 0 && nums[1] < 0) {
        //     temp = nums[0] * nums[1] * nums[n-1];
        // }
        // return std::max(nums[n-1] * nums[n-2] * nums[n-3], temp);
        
        
        // One pass time: O(n)
        int maxs[3];
        int mins[2];
        for (int i = 0; i < 3; i++) {
            maxs[i] = INT_MIN;
            if (i == 2) continue;
            mins[i] = INT_MAX;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (maxs[2] < nums[i]) {
                maxs[0] = maxs[1];
                maxs[1] = maxs[2];
                maxs[2] = nums[i];
            }
            else if (maxs[1] < nums[i]) {
                maxs[0] = maxs[1];
                maxs[1] = nums[i];
            }
            else if (maxs[0] < nums[i]) {
                maxs[0] = nums[i];
            }
            if (mins[1] > nums[i]) {
                mins[0] = mins[1];
                mins[1] = nums[i];
            }
            else if (mins[0] > nums[i]) {
                mins[0] = nums[i];
            }
        }

        int res1 = maxs[2] * maxs[1] * maxs[0];
        int res2 = mins[0] * mins[1] * maxs[2];
        return res1 > res2 ? res1 : res2;
    }
};
/* sorting
Runtime: 68 ms, faster than 38.05% of C++ online submissions for Maximum Product of Three Numbers.
Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Maximum Product of Three Numbers.

one-pass
Runtime: 48 ms, faster than 82.01% of C++ online submissions for Maximum Product of Three Numbers.
Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Maximum Product of Three Numbers.

there is someone using DP, his idea is similar of finding the top3 max and top3 min; I think his soln may need more time as he caculates the max-product and min-product everytime
*/
