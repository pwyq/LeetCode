class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int j = 0; j < A.size(); j++) {
            reverse(A[j], A[j].size());
            for (int i = 0; i < A[j].size(); i++) {
                A[j][i] = 1 - A[j][i];
            }
        }
        return A;
    }
    
    // pass by reference
    void reverse(vector<int> &arr, int n)
    {
        for (int low = 0, high = n - 1; low < high; low++, high--) {
            swap(arr[low], arr[high]);
        }
    }
};

// Runtime: 12 ms, faster than 94.51% of C++ online submissions for Flipping an Image.
// Memory Usage: 9.5 MB, less than 60.21% of C++ online submissions for Flipping an Image.


    // vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    //     for (auto & row : A) reverse(row.begin(), row.end());
    //     for (auto & row : A) for (int & i: row) i ^= 1;
    //     return A;
    // }
