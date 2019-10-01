#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void print_vec(vector<int> a) {
    for (int i : a)
        cout << i << " ";
    cout << endl;
}

// Thanks to dalao
class Solution {
public:
    vector<int> pancakeSort(vector<int> A) {
        vector<int> res;
        int x,i;
        for (x = A.size(); x > 0; --x) {
            for (i = 0; A[i] != x; ++i);
            // cout << "x = " << x << ", A[i] = " << A[i] << endl;
            // first reverse, we put x (current maximum) to A[0]
            if (i != 0) {   // we don't want to push 1 on the stack, same below       
                reverse(A.begin(), A.begin() + i + 1);
                res.push_back(i + 1);
            }
            /// second reverse, we put x to A[x-1]
            if (x != 1) {                
                reverse(A.begin(), A.begin() + x);
                res.push_back(x);
            }
        }
        return res;
    }
};

bool testResult(vector<int> a, vector<int> b) {
    for (int i : b) {
        if (i == a.size())
            reverse(a.begin(), a.end());
        else
            reverse(a.begin(), a.begin()+i);
        print_vec(a);
    }
    return is_sorted(a.begin(), a.end());
}

int main() {
//    vector<int> A = {2,1};
    vector<int> A = {3,2,4,1};
//    vector<int> A = {3,1,2};
//    vector<int> A = {3,1,2};
    vector<int> res= Solution().pancakeSort(A);
    cout << "\n\n ------- result ------- \n\n";
    print_vec(res);
    cout << "---------------------" << endl;
    bool test1 = testResult(A, res);
    assert(test1 == true);
    return 0;
}
