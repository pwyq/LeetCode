// My intuition was:
// while (shift k times)
//     shift one at a time
// This led to TLE (time limit exceeded) issue...


// https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C%2B%2B-solutions
// I thought of swapping too...
// triple-reverse is quite interesting...
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k % n == 0) return;
        k = k % n;
        
        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n-k+i];
        }
        for (int i = n-1; i >= 0; i--) {
            if (i >= k)
                nums[i] = nums[i-k];
            else
                nums[i] = temp[i];
        }
        return;
    }
};

// 1 2 3 4 5 6
// 6 1 2 3 4 5 k=1, a[0]=a[n-1]
// 5 6 1 2 3 4 k=2, a[0]=a[n-2], a[1] = a[n-1]
// 4 5 6 1 2 3 k=3, a[0]=a[n-3], a[1] = a[n-2], a[2] = a[n-1]
// a[i] = a[n-k+i]

// Runtime: 16 ms, faster than 85.10% of C++ online submissions for Rotate Array.
// Memory Usage: 9.5 MB, less than 80.56% of C++ online submissions for Rotate Array.
