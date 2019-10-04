#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    int binaryGap(int N) {
        int curr = -1;
        int prev = -1;
        int res = 0;
        int bits = 0;
        while (N > 0) {
            if (N & 1 == 1) {
                if (curr == -1)
                    curr = bits;
                else {
                    prev = curr;
                    curr = bits;
                    res = max(res, curr-prev);
                }
            }
            bits++;
            N = N >> 1;
        }
        return res;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Gap.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Binary Gap.

int main() {
    int r1 = Solution().binaryGap(22);
    cout << r1 << endl;
    assert(r1 == 2);

    int r2 = Solution().binaryGap(5);
    cout << r2 << endl;
    assert(r2 == 2);

    int r3 = Solution().binaryGap(6);
    cout << r3 << endl;
    assert(r3 == 1);

    int r4 = Solution().binaryGap(8);
    cout << r4 << endl;
    assert(r4 == 0);
    return 0;
}
