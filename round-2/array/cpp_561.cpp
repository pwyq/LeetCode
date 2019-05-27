class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        // for (int i = 0; i < nums.size(); i+=2) {
        //     res += min(nums[i], nums[i+1]);
        // }
        // return res;
        // Runtime: 72 ms, faster than 88.78% of C++ online submissions for Array Partition I.
        // Memory Usage: 11.4 MB, less than 59.32% of C++ online submissions for Array Partition I.
        
        for (int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
        // Runtime: 76 ms, faster than 78.69% of C++ online submissions for Array Partition I.
        // Memory Usage: 11.4 MB, less than 58.32% of C++ online submissions for Array Partition I.
        
        
        // LMAO, why runtime increased after removing a redundant API call?
    }
};
