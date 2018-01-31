/**
 * File              : 001.h
 * Author            : Yanqing Wu <meet.yanqing.wu@gmail.com>
 * Date              : 30.01.2018
 * Last Modified Date: 30.01.2018
 * Last Modified By  : Yanqing Wu <meet.yanqing.wu@gmail.com>
 */

// Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int num1 = nums[i];
            for (int j = i+1; j < nums.size(); j++) {
                int num2 = nums[j];
                if ((num1 + num2) == target)
                    return { i, j };
            }
        }
    }
};


// One online soln
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) { mapping[nums[i]] = i; }
        for (int i = 0; i < nums.size(); i++) {
            const int gap = target - nums[i];
            if(mapping.find(gap) != mapping.end() && mapping[gap] > i) {
                result.push_back(i);
                result.push_back(mapping[gap]);
                break;
            }
        }
        return result;
    }
};