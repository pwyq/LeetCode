#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <climits>
#include <cassert>
using namespace std;
class Solution {
public:
    // O(n) | O(n)
    int equalSubstring(string s, string t, int max_cost) {
        int n = s.length();
        vector<int> costs;
        for (int i = 0; i < n; i++)
            costs.push_back(abs(s[i]-t[i]));
        
        int cost = 0;
        int len = 0;
        int l = 0;
        int r = 0;
        for (; r < n; r++) {
            cost += costs[r];
            while (cost > max_cost && l <= r) {
                cost -= costs[l];
                l++;
            }
            len = max(len, r-l+1);
        }
        return len;
    }

    // Thanks to dalao
    // Sliding window without extra space O(n) | O(1)
    int equalSubstring2(string s, string t, int max_cost) {
        int r = 0, l = 0;
        while (r < s.size()) {
            max_cost -= abs(s[r] - t[r++]);
            if (max_cost < 0) max_cost += abs(s[l] - t[l++]);
        }
        return r - l;
    }

    void print_vec(vector<int> v) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
};

int main() {

    int test1 = Solution().equalSubstring("abcd", "bcdf", 3);
    assert(test1 == 3);

    int test2 = Solution().equalSubstring("abcd", "cdef", 3);
    assert(test2 == 1);

    int test3 = Solution().equalSubstring("abcd", "bcdd", 3);
    assert(test3 == 4);

    int test4 = Solution().equalSubstring("abcd", "bccd", 3);
    assert(test4 == 4);

    int test5 = Solution().equalSubstring("abcd", "acde", 0);
    assert(test5 == 1);

    int test6 = Solution().equalSubstring("abcd", "cdef", 1);
    assert(test6 == 0);

    int test7 = Solution().equalSubstring("vjlqwkzamvyv", "suusjpqkhlkz", 7);
    assert(test7 == 1);

    int test8 = Solution().equalSubstring("krpgjbjjznpzdfy", "nxargkbydxmsgby", 14);
    assert(test8 == 4);

    int test9 = Solution().equalSubstring("ujteygggjwxnfl", "nstsenrzttikoy", 43);
    assert(test9 == 5);

    return 0;
}

