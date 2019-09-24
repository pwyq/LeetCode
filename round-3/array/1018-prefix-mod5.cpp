class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int n = A.size();
        int num = 0;
        
        for(int i=0; i<n; i++)
        {
            num = num*2 + A[i]; // binary left shift one-bit is the same as multiply by 2
            num %= 5;           // since we only care about the remainder
            res.push_back(num%5 == 0);
        }
        
        return res;
    }
};
