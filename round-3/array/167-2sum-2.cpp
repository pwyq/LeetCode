class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        
        // binary search
        while (nums[l] + nums[h] != target) {
            if (nums[l] + nums[h] < target) {
                l++;
            }
            else {
                h--;
            }
        }
        return vector<int>({l+1, h+1});
    }
};
/*Runtime: 4 ms, faster than 96.94% of C++ online submissions for Two Sum II - Input array is sorted.
Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Two Sum II - Input array is sorted.*/
