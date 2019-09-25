// My
// Runtime: 176 ms, faster than 57.68% of C++ online submissions for Maximum Average Subarray I.
// Memory Usage: 20.5 MB, less than 33.33% of C++ online submissions for Maximum Average Subarray I.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> cnt(n-k+1, 0);                   // no need to store every result
        
        for (int i = 0; i < k; i++)                     // redundant, can do it in the for-loop
            cnt[0] += nums[i];
        cnt[0] /= k;
        
        double res = cnt[0];
        for (int i = k, j=1; i < n; i++, j++) {
            cnt[j] = (cnt[j-1]*k-nums[j-1]+nums[i])/k;  // can do division at final step
            res = max(res, cnt[j]);
        }
        return res;
    }
};


// The related problem is Maximum Average Subarray II, which the length can be >= k;
// dalao
// Runtime: 168 ms, faster than 93.06% of C++ online submissions for Maximum Average Subarray I.
// Memory Usage: 16.7 MB, less than 100.00% of C++ online submissions for Maximum Average Subarray I.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0, res=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            if(i<k) sum+=nums[i];
            else {
                res=max(sum, res);
                sum+=nums[i]-nums[i-k];
            }
        }
        res=max(sum, res);  // takes care when n==k
        return res/k;
    }
};

