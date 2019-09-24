class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> t;
        
        for (int i = 0; i < nums.size(); i++) {
            if (t.count(target-nums[i]))
                return {t[target-nums[i]], i};
            else
                t[nums[i]] = i;
        }
        return {0,0}; 
        
        // following FAILS when there is identical element, because we iter thru all elements, the new pair would overwrite the old pair;
        // while the above returns the identical case immediately instead of overwrite!!
        
        
//         map<int, int> t;
//         for (int i = 0; i < nums.size(); i++) {
//             // t.insert({nums[i], i});
//             t[nums[i]] = i;
//         }
        
//         for (auto p : t) {
//             cout << p.first << "->" << p.second << endl;
//         }
        
//         for (auto p : t) {
//             int diff = target - p.first;
//             if (t.count(diff)) {
//                 return {t[diff], p.second};
//             }
//         }

//         return {0,0};
    }
};

// first touch this problem is 20 months ago :)
