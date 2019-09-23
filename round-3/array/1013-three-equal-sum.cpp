class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
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
