class Solution {
public:
    void merge(vector<int>& x, int m, vector<int>& y, int n) {
        int a = m-1;
        int b = n-1;
        int c = m+n-1;
        
        while (a >= 0 && b >= 0) {
            if (x[a] > y[b]) {
                x[c--] = x[a--];
            }
            else {
                x[c--] = y[b--];
            }
        }
        
        while (b >= 0) { // y.size > x.size
            x[c--] = y[b--];
        }
        return;
    }
};


// when y.size > x.size; note that [0] means x is empty
/*
[0]
0
[1]
1
*/

// thanks dalao
