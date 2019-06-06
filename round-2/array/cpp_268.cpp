class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // unsorted order
        // int res = 1;
        // for (int i = 0; i < nums.size()+1; i++) {
        //     if (std::find(nums.begin(), nums.end(), i) == nums.end()) {
        //         res = i;
        //         break;
        //     }
        // }
        // return res;
// Runtime: 400 ms, faster than 6.04% of C++ online submissions for Missing Number.
// Memory Usage: 9.9 MB, less than 26.83% of C++ online submissions for Missing Number.
        
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size()+1; i++) {
        //     if (!std::binary_search(nums.begin(), nums.end(), i)) {
        //         return i;
        //     }
        // }
        // return 1;     
// Runtime: 32 ms, faster than 29.13% of C++ online submissions for Missing Number.
// Memory Usage: 10.1 MB, less than 9.33% of C++ online submissions for Missing Number.
        
//         int result = nums.size();
//         int i=0;
        
//         for(int num:nums){
//             // using the fact that a^b^b = a
//             result ^= num;
//             result ^= i;
//             i++;
//         }
        
//         return result;
// Runtime: 24 ms, faster than 92.22% of C++ online submissions for Missing Number.
// Memory Usage: 9.9 MB, less than 21.64% of C++ online submissions for Missing Number.
        
        // math
        // long n = nums.size();
        // return n*(n+1)/2 - accumulate(nums.begin(), nums.end(), 0);
// Runtime: 24 ms, faster than 92.22% of C++ online submissions for Missing Number.
// Memory Usage: 10 MB, less than 11.69% of C++ online submissions for Missing Number.
        int sum = nums.size()*(nums.size()+1) / 2;
        for(auto x:nums)
            sum-=x;
        return sum;
// Runtime: 16 ms, faster than 98.51% of C++ online submissions for Missing Number.
// Memory Usage: 10.1 MB, less than 8.74% of C++ online submissions for Missing Number.
//         int missingNo = 0;
        
//         for(int index = 0; index < nums.size(); ++index) {
//             missingNo ^= index;
//             missingNo ^= nums[index];
//         }

//         missingNo ^= nums.size();
        
//         return missingNo;
    }
};
