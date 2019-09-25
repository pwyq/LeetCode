class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (target <= nums[0]) return 0;
        if (target > nums[n-1]) return n;
        
        int res = -1;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == target) return i;
            if (nums[i] <= target && target <= nums[i+1])
                res = i+1;
        }
        return res;
    }
};

/*
Runtime: 8 ms, faster than 58.75% of C++ online submissions for Search Insert Position.
Memory Usage: 8.9 MB, less than 57.81% of C++ online submissions for Search Insert Position.
*/

//optimization: to use binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        
        while (l <= r) {
            cout << "l = " << l << ", r = " << r << endl;
            int m = l + (r-l) / 2; // prevent overflow
            if (nums[m] == target) return m;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
};

/*
Runtime: 4 ms, faster than 98.49% of C++ online submissions for Search Insert Position.
Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Search Insert Position.*/
