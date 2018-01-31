/**
 * File              : 009.h
 * Author            : Yanqing Wu <meet.yanqing.wu@gmail.com>
 * Date              : 30.01.2018
 * Last Modified Date: 30.01.2018
 * Last Modified By  : Yanqing Wu <meet.yanqing.wu@gmail.com>
 */

// Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        int result = 0;
        int temp = x;
        while(temp) {
            result = result * 10 + temp % 10;
            temp = temp / 10;
        }
        if (x < 0) { return false; }
        return (result == x) ? true : false;
    }
};