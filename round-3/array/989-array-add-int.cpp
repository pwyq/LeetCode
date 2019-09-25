class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int k) {
        // since the size of A is huge, we cannot convert to int then convert back
        
        vector<int> temp;
        while (k > 0) {
            temp.push_back(k % 10);
            k = k / 10;
        }
        std::reverse(A.begin(), A.end());
        A.resize(max(A.size(), temp.size()) + 1);
        for (int i = 0; i < A.size(); i++) {
            if (i < temp.size()) {
                A[i] += temp[i];                
            }
            if (A[i] >= 10) {
                A[i] = A[i] % 10;
                A[i+1]++;
            }
        }
        if (A.back() == 0) {
            A.pop_back();
        }
        std::reverse(A.begin(), A.end());
        return A;        
    }
};

/*Runtime: 116 ms, faster than 60.47% of C++ online submissions for Add to Array-Form of Integer.
Memory Usage: 13.2 MB, less than 44.44% of C++ online submissions for Add to Array-Form of Integer.*/
