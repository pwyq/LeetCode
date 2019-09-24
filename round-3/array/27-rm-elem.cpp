class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Check 283 as well
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Remove Element.
        
        // int j = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     print_vec(nums);
        //     if (nums[i] != val) {
        //         nums[j++] = nums[i];
        //     }
        // }
        // return j;
// Runtime: 20 ms, faster than 5.16% of C++ online submissions for Remove Element.
// Memory Usage: 9.4 MB, less than 5.88% of C++ online submissions for Remove Element.
    }
    
    void print_vec(vector<int> x) {
        for (auto i : x)
            cout << i << " ";
        cout << endl;
    }
};
