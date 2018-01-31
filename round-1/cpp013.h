/**
 * File              : cpp013.h
 * Author            : Yanqing Wu <meet.yanqing.wu@gmail.com>
 * Date              : 30.01.2018
 * Last Modified Date: 30.01.2018
 * Last Modified By  : Yanqing Wu <meet.yanqing.wu@gmail.com>
 */

// Roman to Integer

// Libraries for testing
#include <string>
#include <unordered_map>
#include <iostream>
using std::string;
using std::unordered_map;

// One online soln
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = {{'I', 1},
                                      {'V', 5},
                                      {'X', 10},
                                      {'L', 50},
                                      {'C', 100},
                                      {'D', 500},
                                      {'M', 1000}};
        int sum = T[s.back()];
        for (int i = s.length()-2; i >= 0; --i) {
            std::cout << "i = " << i << ", " << T[s[i]] << ", " <<  T[s[i+1]] << std::endl;
            if (T[s[i]] < T[s[i+1]])
                sum -= T[s[i]];
            else
                sum += T[s[i]];
        }
        return sum;
    }
};
