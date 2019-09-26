// THANKS dalao
// Don't know you can use set to store unique value
//
// waste 90 mins on this problem
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_set<int> starters;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(nums[i] - k)) {
                starters.insert(nums[i] - k);
            }
            if (indices.count(nums[i] + k)) {
                starters.insert(nums[i]);
            }

            indices[nums[i]] += 1;
            // print_set(starters);
        }
        
        return starters.size();
    }
    
    void print_set(unordered_set<int> myset) {
        for (auto it=myset.begin(); it != myset.end(); ++it) 
            cout << ' ' << *it; 
        cout << endl;
    }
};

