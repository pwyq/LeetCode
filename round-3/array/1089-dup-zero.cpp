/*Runtime: 60 ms, faster than 9.53% of C++ online submissions for Duplicate Zeros.
Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Duplicate Zeros.*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        for (int i = 0; i < size-1; i++) {
            if (arr[i] == 0) {
                for (int j = size-1; j > i; j--) {
                    arr[j] = arr[j-1];
                }
                arr[++i] = 0;
            }
        }

    }
};

/*
 * 20ms, 75%; 9.1MB 100%

basic idea is avoid duplicate too early by using backwards scan

class Solution {
public:
    void duplicateZeros(vector<int>& A) {
        int n = A.size();
        int j = n + count(A.begin(), A.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            // cout << "i = " << i << ", j = " << j << endl;
            // print_vec(A);
            if (--j < n) {
                A[j] = A[i];
                // cout << "* ";
                // print_vec(A);                
            }
            if (A[i] == 0 && --j < n) {
                A[j] = 0;
                // cout << "# ";
                // print_vec(A);                
            }
        }
    }
    
    void print_vec(vector<int> a) {
        for (auto & i : a) cout << i << " ";
        cout << endl;
    }
};



// following is a lightly easier to understand-version.


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int countZero = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) countZero++;
        }
        int len = arr.size() + countZero;
        //We just need O(1) space if we scan from back
        //i point to the original array, j point to the new location
        for (int i = arr.size() - 1, j = len - 1; i < j; i--, j--) {
            if (arr[i] != 0) {
                if (j < arr.size()) arr[j] = arr[i];
            } else {
                if (j < arr.size()) arr[j] = arr[i];
                j--;
                if (j < arr.size()) arr[j] = arr[i]; //copy twice when hit '0'
            }
        }
    }
};
*/
