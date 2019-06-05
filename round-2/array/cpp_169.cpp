class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // intuition, use a data structure that stores (key, appear times)
        // return the one that has highest appear times -> looks like this is the same as approach2: hashMap
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
        
        // // sort(nums.begin(), nums.end());
        // std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end()); // https://en.cppreference.com/w/cpp/algorithm/nth_element
        // return nums[nums.size()/2];
    }
};

// For std::sort()
// Runtime: 24 ms, faster than 58.55% of C++ online submissions for Majority Element.
// Memory Usage: 11.2 MB, less than 48.08% of C++ online submissions for Majority Element.

// For std::nth_element()
// Runtime: 20 ms, faster than 92.54% of C++ online submissions for Majority Element.
// Memory Usage: 11.2 MB, less than 45.04% of C++ online submissions for Majority Element.

// For hashmap
// Runtime: 20 ms, faster than 92.54% of C++ online submissions for Majority Element.
// Memory Usage: 11.2 MB, less than 45.04% of C++ online submissions for Majority Element.
