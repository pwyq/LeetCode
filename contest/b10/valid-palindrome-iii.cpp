#include <iostream>
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int sz = s.length();
        for (int i = 0; i < sz; i++) {
            if (a[i] == a[sz-1-i]) {
                // match
            }
            else {
                int temp = i;
                while (a[++i] != a[sz-1-i]) {
                }
            }
        }
        return false;
    }
};