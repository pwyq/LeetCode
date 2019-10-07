#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Runtime: 4 ms, faster than 80.10% of C++ online submissions for Add Binary.
// Memory Usage: 8.5 MB, less than 94.55% of C++ online submissions for Add Binary.
class Solution {
public:
    string addBinary(string a, string b) {
        string res(max(a.length(), b.length())+1, ' ');

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0;
        int carry = 0;
        int min_size = min(a.length(), b.length());
        for (; i < min_size; i++) {
            if (a[i] == '1' && b[i] == '1') {
                res[i] = (carry == 1) ? '1' : '0';
                carry = 1;
            }
            else if (a[i] == '1' || b[i] == '1')
                res[i] = (carry == 1) ? '0' : '1';
            else {
                res[i] = (carry == 1) ? '1' : '0';
                carry = 0;
            }
        }

        if (i == a.length() && i != b.length()) {
            for (; i < b.length(); i++) {
                if (b[i] == '1')
                    res[i] = (carry == 1) ? '0' : '1';
                else {
                    res[i] = (carry == 1) ? '1' : '0';
                    carry = 0;
                }
            }
        }
        else if (i == b.length() && i != a.length()) {
            for (; i < a.length(); i++) {
                if (a[i] == '1')
                    res[i] = (carry == 1) ? '0' : '1';
                else {
                    res[i] = (carry == 1) ? '1' : '0';
                    carry = 0;
                }
            }
        }
        res[i] = char(carry+'0');
        if (res[i] == '0')
            res = res.substr(0, res.length() - 1);
        reverse(res.begin(), res.end());
        return res;
    }

/* Short solution
    string addBinary(string a, string b)
    {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
*/
};

int main() {
    assert(Solution().addBinary("11", "1") == "100");
    assert(Solution().addBinary("1", "11") == "100");
    assert(Solution().addBinary("1010", "1011") == "10101");
    assert(Solution().addBinary("1011", "1010") == "10101");
    assert(Solution().addBinary("0", "0") == "0");
    assert(Solution().addBinary("0", "1") == "1");
    assert(Solution().addBinary("1", "0") == "1");
    assert(Solution().addBinary("1", "1") == "10");
    assert(Solution().addBinary("111111111111111111", "1") == "1000000000000000000");
    assert(Solution().addBinary("111111111111111111", "0") == "111111111111111111");
    assert(Solution().addBinary("1", "111111111111111111") == "1000000000000000000");
    assert(Solution().addBinary("0", "111111111111111111") == "111111111111111111");
    assert(Solution().addBinary("1", "111111111111111101") == "111111111111111110");
    assert(Solution().addBinary("111111111111111101", "1") == "111111111111111110");
    assert(Solution().addBinary("1111", "1111") == "11110");
    return 0;
}
