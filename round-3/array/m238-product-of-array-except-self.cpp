// challenge
// 1. no division               <= didn't achieve this
// 2. O(n) runtime O(1) space
// 3. One-pass
class Solution {
public:
    /* dalao's solution without division
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int fromBegin = 1;
        int fromLast = 1;
        vector<int> res(n,1);
        
        for(int i = 0; i < n; i++){
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n-1-i] *= fromLast;
            fromLast *= nums[n-1-i];
            cout << fromBegin << ", " << fromLast << endl;
            print_vec(res);
        }
        return res;
    }
input: [1,2,3,4,5,6,7,8,0,9]
1, 9
1 1 1 1 1 1 1 1 1 1 
2, 0
1 1 1 1 1 1 1 1 9 1 
6, 0
1 1 2 1 1 1 1 0 9 1 
24, 0
1 1 2 6 1 1 0 0 9 1 
120, 0
1 1 2 6 24 0 0 0 9 1 
720, 0
1 1 2 6 0 0 0 0 9 1 
5040, 0
1 1 2 0 0 0 0 0 9 1 
40320, 0
1 1 0 0 0 0 0 0 9 1 
0, 0
1 0 0 0 0 0 0 0 362880 1 
0, 0
0 0 0 0 0 0 0 0 362880 0 
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 0;
        int zero_count = 0;
        for (int i : nums) {
            if (i != 0)
                total = (total == 0) ? i : i*total;
            else
                zero_count++;
        }
        
        vector<int> res(nums.size(), 0);
        if (zero_count >= 2) return res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                res[i] = total;
            else {
                if (zero_count > 0)
                    res[i] = 0;
                else
                    res[i] = total / nums[i];
            }
        }
        return res;
    }
};

// watch out for 0 when there is division!!!
Runtime: 40 ms, faster than 81.92% of C++ online submissions for Product of Array Except Self.
Memory Usage: 12.6 MB, less than 71.21% of C++ online submissions for Product of Array Except Self.
