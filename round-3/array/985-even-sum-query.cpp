class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        
        int cnt = 0;
        for (int j = 0; j < A.size(); j++) {
            if (A[j] % 2 == 0) {
                cnt += A[j];
            }
        }
        
        for (int i = 0; i < queries.size(); i++) {
            int o = A[queries[i][1]];   // original
            bool f = (o % 2 == 0) ? true : false;
           
            A[queries[i][1]] += queries[i][0];
            
            if (f && A[queries[i][1]] % 2 == 0) {
                cnt += queries[i][0];
            }
            else if (f && A[queries[i][1]] % 2 != 0) {
                cnt -= o;
            }
            else if (!f && A[queries[i][1]] % 2 == 0) {
                cnt += A[queries[i][1]];
            }
            res.push_back(cnt);
        }
        return res;
    }
};

/*
 * Runtime: 156 ms, faster than 81.58% of C++ online submissions for Sum of Even Numbers After Queries.
Memory Usage: 28.9 MB, less than 100.00% of C++ online submissions for Sum of Even Numbers After Queries.
 * /
