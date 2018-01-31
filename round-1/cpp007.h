/**
 * File              : 007.h
 * Author            : Yanqing Wu <meet.yanqing.wu@gmail.com>
 * Date              : 30.01.2018
 * Last Modified Date: 30.01.2018
 * Last Modified By  : Yanqing Wu <meet.yanqing.wu@gmail.com>
 */

// Reverse Integer
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        bool neg = false;
        
        if (x < 0) {
            neg = true;
            x = -x;
        }
        
        while(x) {
            result = result*10 + (x%10);
            x = x / 10;
        }
        
        if (neg) {
            result = -result;
            return (result < INT_MIN || result > INT_MAX) ? 0 : result;
        }
        return (result > INT_MAX || result < INT_MIN) ? 0 : result;
    }
};