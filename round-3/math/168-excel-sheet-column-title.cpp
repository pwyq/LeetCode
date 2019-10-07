#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <climits>
using namespace std;

#define SIZE INT_MAX
// waste a lot of time on implementing directly...
// when I asked myself how would I do if I were the machine
// well, I first tried converting 10-base to 2-base to see the pattern
// then tried converting 10-base to 26-base
// so... lesson here
// **think twice, code once**
// ask yourself how would you do (try some cases)

// Runtime: 4 ms, faster than 48.14% of C++ online submissions for Excel Sheet Column Title.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Excel Sheet Column Title.

class Solution {
public:
    string convertToTitle(int n) { // LC168
        string res = "";
        while (n > 0) {
            int c = n % 26;
            if (c != 0) {
                res += char(c-1+'A');
            }
            else {
                res += 'Z';
                n -= 26;
            }
            n = n / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int titleToNumber(string s) {   // LC171
        int res = 0;
        int len = s.length()-1;
        for (char c : s)
            
        return res;
    }
};



int main() {
    cout << "test size = " << SIZE << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << endl;
        string x = Solution().convertToTitle(i);
        if (i != Solution().titleToNumber(x)) {
            cerr << "error @ " << i << endl;
            break;
        }
    }
    return 0;
}
