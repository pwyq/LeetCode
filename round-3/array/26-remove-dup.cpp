/*Runtime: 156 ms, faster than 16.71% of C++ online submissions for Remove Duplicates from Sorted Array.
Memory Usage: 11.3 MB, less than 5.00% of C++ online submissions for Remove Duplicates from Sorted Array.*/


// check 27, 283 as well

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        unordered_map<int, int> cnt;
        int i = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++, i++) {
            if (++cnt[*it] >= 2) {
                nums.erase(nums.begin()+i);
                i--;
                it--;
            }

        }
        return nums.size();
        */

        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                cnt++;
            }
            else {
                nums[i-cnt] = nums[i];
            }
        }
        nums.erase(nums.end()-cnt, nums.end());
        return nums.size();
    }
};

// Thanks dalao for the second approach
/*
Runtime: 20 ms, faster than 93.09% of C++ online submissions for Remove Duplicates from Sorted Array.
Memory Usage: 10 MB, less than 77.50% of C++ online submissions for Remove Duplicates from Sorted Array.
*/
