class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_a = std::accumulate(A.begin(), A.end(), 0);
        int sum_b = std::accumulate(B.begin(), B.end(), 0);
        int target = (sum_a + sum_b) / 2;
        
        // brute force cause time limit violation
        vector<int> res(2, 0);
        for (int i = 0; i < A.size(); i++) {
            // for (int j = 0; j < B.size(); j++) {
            //     int t1 = sum_a - A[i] + B[j];
            //     int t2 = sum_b + A[i] - B[j];
            //     if (t1 == t2) {
            //         res[0] = A[i];
            //         res[1] = B[j];
            //         break;
            //     }
            // }
            int diff = sum_b + A[i] - target;   // simple algebra from above t2 equation;
            std::vector<int>::iterator it = std::find(B.begin(), B.end(), diff);
            if (it != B.end()) {
                res[0] = A[i];
                res[1] = diff;
                break;
            }
        }
        return res;
    }
};

/*Runtime: 540 ms, faster than 26.06% of C++ online submissions for Fair Candy Swap.
Memory Usage: 12.2 MB, less than 80.00% of C++ online submissions for Fair Candy Swap.*/
