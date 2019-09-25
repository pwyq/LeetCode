class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        
        int l_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int r_sum = sum - nums[i] - l_sum;
            if (l_sum == r_sum)
                return i;
            else
                l_sum += nums[i];
        }
        return -1;
    }
};

/*
 * Runtime: 28 ms, faster than 57.16% of C++ online submissions for Find Pivot Index.
Memory Usage: 9.9 MB, less than 66.67% of C++ online submissions for Find Pivot Index.*/
