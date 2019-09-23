/*
 * Runtime: 128 ms, faster than 15.12% of C++ online submissions for Minimum Absolute Difference.
Memory Usage: 17.8 MB, less than 100.00% of C++ online submissions for Minimum Absolute Difference.
*/

// Interestingly, the uncommented (shorter) version has a longer runtime (20ms+)...
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // sort
        // iterature thru to find min abs diff
        
        std::sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        for (int i = 0; i < arr.size()-1; i++) {
            // int diff = abs(arr[i+1] - arr[i]);
            // if (diff < min_diff) {
            //     min_diff = diff;
            // }
            min_diff = min(abs(arr[i+1]-arr[i]), min_diff);
        }
        
        vector<vector<int>> res;
        
        for (int i = 0; i < arr.size()-1; i++) {
            if (arr[i] + min_diff == arr[i+1]) {
                // vector<int> temp;
                // temp.push_back(arr[i]);
                // temp.push_back(arr[i+1]);
                // res.push_back(temp);
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};
