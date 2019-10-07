#include <iostream>
#include <cassert>
using namespace std;

// 12-16 ms
// 8.2 mb; 100%
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0;
        while (n > 0) {
            i++;
            n -= i;
            if (n <= 0) break;
        }
        return (n == 0) ? i : i-1;
    }
};

int main() {
    assert(Solution().arrangeCoins(5) == 2);
    assert(Solution().arrangeCoins(1) == 1);
    assert(Solution().arrangeCoins(0) == 0);
    assert(Solution().arrangeCoins(8) == 3);
    assert(Solution().arrangeCoins(6) == 3);
    return 0;
}