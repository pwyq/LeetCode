// WITHOUT modification, bidirectional scan
// thanks dalao
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        
        int asc = 0;
        int desc = 0;
        
        int m = 0;
        for (int l = 0, r = n-1; l < n; l++) {
            if (nums[m] > nums[l])
                asc++;
            else
                m = l;
            
            if (nums[r] < nums[n-1-l])
                desc++;
            else
                r = n-1-l;
            
            if (asc > 1 && desc > 1) return false;
        }
        return true;
    }
};



// 7 submissons, ~25min

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> copy(nums);
        int n = nums.size();

        int right = 0;
        for (int i = n-1; i > 0; i--) {
            if (nums[i] < nums[i-1]) {
                right++;
                nums[i-1] = nums[i];
            }
        }

        int left = 0;
        for (int i = 0; i < n-1; i++) {
            if (copy[i] > copy[i+1]) {
                left++;
                copy[i+1] = copy[i];
            }
        }

        return (std::min(left, right) <= 1);
    }
};
// Runtime: 32 ms, faster than 81.28% of C++ online submissions for Non-decreasing Array.
// Memory Usage: 11 MB, less than 15.00% of C++ online submissions for Non-decreasing Array.

// [4,2,1]
// [2,3,3,2,4]

// [3,2,3,2,4]
// [3,4,2,3]
// [-1,4,2,3]



// FOLLOWING ARE INITIAL THOUGHT, it does NOT work.

        // int n = nums.size();
//         if (n == 1) return true;
//         if (n == 2) return (nums[0] <= nums[1]) ? true : false;
//         if (n == 3) {
//             if (nums[0] > nums[1])
//                 if (nums[1] > nums[2])
//                     return false;
//             return true;
//         }

//         int res = 0;
//         for (int i = n-2; i > 0; i--) {
//             if (nums[i-1] > nums[i] || nums[i] > nums[i+1])
//                 res++;
//         }
//         return (res <= 1);
