// mother fucker, i feel i got played tried 8 submissions, ~40mins on this "simple" problem

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        vector<int> res(3, INT_MIN);
        set<int> fkYouIamusingset;

        bool theNumberHasCome = false;
        for (int i = 0; i < nums.size(); i++) {
            fkYouIamusingset.insert(nums[i]);
            if (nums[i] == INT_MIN) {
                theNumberHasCome = true;
            }
            if (nums[i] > res[0]) {
                res[2] = res[1];
                res[1] = res[0];
                res[0] = nums[i];
            }
            else if (nums[i] > res[1] && nums[i] != res[0]) {
                res[2] = res[1];
                res[1] = nums[i];
            }
            else if (nums[i] > res[2] && nums[i] != res[1] && nums[i] != res[0]) {
                res[2] = nums[i];
            }
        }

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        bool fk = (theNumberHasCome || res[2] != INT_MIN) && (nums.size() > 2) && (fkYouIamusingset.size() > 2);
        return fk ? res[2] : res[0];
    }
};

// Runtime: 12 ms, faster than 35.46% of C++ online submissions for Third Maximum Number.
// Memory Usage: 10.5 MB, less than 46.15% of C++ online submissions for Third Maximum Number.

// [1,2,-2147483648]
// [1,2,2,5,3,5]
// [1,-2147483648,2]
// [5,2,2]
// [2, -2147483648]
// [-2147483648,1,1]

int thirdMax(vector<int>& nums) {
    set<int> top3;
    for (int num : nums)
        if (top3.insert(num).second && top3.size() > 3)
            top3.erase(top3.begin());
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}

int thirdMax(vector<int>& nums) {
    set<int> top3;
    for (int num : nums) {
        top3.insert(num);
        if (top3.size() > 3)
            top3.erase(top3.begin());
    }
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}
