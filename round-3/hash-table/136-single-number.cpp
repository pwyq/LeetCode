class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // requirements: O(n) time, O(1) space
        
        // THANKS to dalao, use XOR!!!!!!
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res = res ^ nums[i];
        }
        return res;
        
        // I can't...
        // my O(2*n) time, O(n) space soln, beats ~35% 35%
        // unordered_map<int, int> mm;
        // for (auto i : nums)
        //     mm[i]++;
        // for (auto it = mm.begin(); it != mm.end(); it++) {
        //     if (it->second == 1) {return it->first;}
        // }
        // return 0;
    }
};
