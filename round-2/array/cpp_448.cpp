class Solution {
public:
    // brute force exceeds time limits
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         if (nums.size() == 0) return {};
//         // note max_element is an iterator
//         // int max = *max_element(nums.begin(), nums.end());
//         // int min = *min_element(nums.begin(), nums.end());
//         vector<int> res;
//         for (int i = 1; i <= nums.size(); i++) {
//             // for unsorted finding; if sorted, then we can use binary_search
//             // if (find(nums.begin(), nums.end(), i) == nums.end()) {
//             //     // i'th not found in nums
//             //     res.push_back(i);
//             // }
            
//             if (find(nums.begin(), nums.end(), i) != nums.end()) {
//                 remove(nums.begin(), nums.end(), i);
//             }
//         }
//         return nums;
//     }

    
    // mark and sweep! (looks like)
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int val = std::abs(nums[i]) - 1;
            // cout << val << " ";
            if (nums[val] > 0)
                nums[val] = -nums[val];
        }
        // cout << "\n------" << endl;
        // for (int x : nums)
            // cout << x << ", ";
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};

// Runtime: 108 ms, faster than 96.64% of C++ online submissions for Find All Numbers Disappeared in an Array.
// Memory Usage: 14.9 MB, less than 77.06% of C++ online submissions for Find All Numbers Disappeared in an Array.
