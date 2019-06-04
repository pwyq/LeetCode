class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        // intuition: [brute force] put bar between balls:  oooo|ooo|oo
        // check if each part's sum equals, moving bars for each iteration
        // is there more efficient way? dynamic programming?
        // this exceeded time limit
        // time complexity: O(n^2)
        // int sum1 = 0;
        // int sum2 = 0;
        // int sum3 = 0;
        // for (int i = 1; i < A.size(); i++) {
        //     for (int j = i+1; j < A.size(); j++) {
        //         // cout << "i = " << i << ", j = " << j << endl;
        //         sum1 = std::accumulate(A.begin(), A.begin()+i, 0);
        //         sum2 = std::accumulate(A.begin()+i, A.begin()+j, 0);
        //         sum3 = std::accumulate(A.begin()+j, A.end(), 0);
        //         // cout << "s1 = " << sum1 << ", s2 = " << sum2 << ", s3 = " << sum3 << endl;
        //         if (sum1 == sum2 && sum2 == sum3) {
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
        // Note: observe that the total-sum of A = 3 * each part
        int total = std::accumulate(A.begin(), A.end(), 0);
        if (total % 3 != 0) return false;
        
        int parts = 0;
        for (int i = 0, sum = 0; i < A.size() && parts < 2; i++) {
            sum += A[i];
            if (sum == total/3) {
                parts++;
                sum = 0;
            }
        }
        return (parts == 2);
    }
};

// Runtime: 72 ms, faster than 31.55% of C++ online submissions for Partition Array Into Three Parts With Equal Sum.
// Memory Usage: 12.6 MB, less than 46.24% of C++ online submissions for Partition Array Into Three Parts With Equal Sum.
