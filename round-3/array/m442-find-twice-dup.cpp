// Thanks to dalao for the very smart answer!
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    // Since all intergers are positive and bounded by the size of array, we can use negation to mark visited numbers!!
    
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // print_vec(nums);
            int index = std::abs(nums[i])-1;
            // cout << "index = " << index << ", nums[i] = " << nums[i] << ", nums[index] = " << nums[index] << endl;
            if (nums[index] < 0)
                res.push_back(index + 1);
            nums[index] = -nums[index];
        }
        return res;
    }
    
    // void print_vec(vector<int> n) {
    //     for (int i : n)
    //         cout << i << " ";
    //     cout << endl;
    // }
};
// 4 3 2 7 8 2 3 1 1 
// index = 3, nums[i] = 4, nums[index] = 7
// 4 3 2 -7 8 2 3 1 1 
// index = 2, nums[i] = 3, nums[index] = 2
// 4 3 -2 -7 8 2 3 1 1 
// index = 1, nums[i] = -2, nums[index] = 3
// 4 -3 -2 -7 8 2 3 1 1 
// index = 6, nums[i] = -7, nums[index] = 3
// 4 -3 -2 -7 8 2 -3 1 1 
// index = 7, nums[i] = 8, nums[index] = 1
// 4 -3 -2 -7 8 2 -3 -1 1 
// index = 1, nums[i] = 2, nums[index] = -3
// 4 3 -2 -7 8 2 -3 -1 1 
// index = 2, nums[i] = -3, nums[index] = -2
// 4 3 2 -7 8 2 -3 -1 1 
// index = 0, nums[i] = -1, nums[index] = 4
// -4 3 2 -7 8 2 -3 -1 1 
// index = 0, nums[i] = 1, nums[index] = -4
