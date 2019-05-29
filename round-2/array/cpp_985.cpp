class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        // force soln exceeds time
        vector<int> res;
        int initSum = findSum(A);
        // 4 possibilities
        // even -> even; even -> odd; odd -> even; odd -> odd (x)
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i][1];
            int val = queries[i][0];
            // int tmp = A[idx] + val;
            // bool isEven = (tmp % 2 == 0);
            // if (A[idx] % 2 == 0) {
            //     if (isEven) {
            //         initSum += val;
            //     }
            //     else {
            //         initSum -= A[idx];
            //     }
            // }
            // else{
            //     if (isEven) {
            //         // odd -> even
            //         initSum += tmp;
            //     }
            // }
            // A[idx] = tmp;
            
            // From one post, this is more clever, but didn't improve runtime/mem usage (weird)
            if (A[idx] % 2 == 0) {
                initSum -= A[idx];
            }
            A[idx] += val;
            if (A[idx] % 2 == 0) {
                initSum += A[idx];
            }
            res.push_back(initSum);
        }
        return res;
    }
    
// Runtime: 184 ms, faster than 37.08% of C++ online submissions for Sum of Even Numbers After Queries.
// Memory Usage: 29.6 MB, less than 28.64% of C++ online submissions for Sum of Even Numbers After Queries.

// After reducing redundant if-else statements...
// Runtime: 156 ms, faster than 93.80% of C++ online submissions for Sum of Even Numbers After Queries.
// Memory Usage: 29.5 MB, less than 32.36% of C++ online submissions for Sum of Even Numbers After Queries.

    
// Runtime drops by half for the large test cases... but result didn't change? or even worse?
// Runtime: 156 ms, faster than 93.80% of C++ online submissions for Sum of Even Numbers After Queries.
// Memory Usage: 29.5 MB, less than 29.79% of C++ online submissions for Sum of Even Numbers After Queries.
    int findSum(vector<int> A) {
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) {
                sum += A[i];
            }
        }
        return sum;
    }
};
