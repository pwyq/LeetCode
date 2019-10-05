// the minimum element always increase 1 until it reaches sum-num_element
// thanks dalao
class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0L) - nums.size() * *min_element(begin(nums), end(nums));
    }
};
