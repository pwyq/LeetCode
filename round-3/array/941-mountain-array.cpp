class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3) return false;
        
        int l = 0;
        while(A[l] < A[l+1] && (l < n)) {
            l++;
            if (l == n-1) return false;
        }
        int r = n-1;
        while(A[r] < A[r-1] && (r >= 0)) {
            cout << r << " ";
            r--;
            if (r == 0) return false;
        }
        // cout << l << ", " << r << endl;
        return (l==r);
    }
};

// It looks like a very simple problem, but it took me 5 tries...

// Runtime: 40 ms, faster than 29.85% of C++ online submissions for Valid Mountain Array.
// Memory Usage: 10.4 MB, less than 81.25% of C++ online submissions for Valid Mountain Array.
