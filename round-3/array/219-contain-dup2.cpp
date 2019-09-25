class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> t;//val,idx
        
        for (int i = 0; i < nums.size(); i++) {
            if (!t.count(nums[i])) {
                t[nums[i]] = i;
            }
            else {
                if ((i-t[nums[i]]) <= k)
                    return true;
                else
                    t[nums[i]] = i;
            }
        }
        return false;
    }
};

// Runtime: 28 ms, faster than 85.81% of C++ online submissions for Contains Duplicate II.
// Memory Usage: 15.5 MB, less than 52.94% of C++ online submissions for Contains Duplicate II.
