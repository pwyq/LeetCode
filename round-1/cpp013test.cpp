/**
 * File              : test013.cpp
 * Author            : Yanqing Wu <meet.yanqing.wu@gmail.com>
 * Date              : 30.01.2018
 * Last Modified Date: 30.01.2018
 * Last Modified By  : Yanqing Wu <meet.yanqing.wu@gmail.com>
 */

#include <iostream>
#include "cpp013.h"


int main() {
    Solution obj;
    int result1 = obj.romanToInt("MDIC");
    int result2 = obj.romanToInt("C");
    std::cout << result1 << std::endl;
    std::cout << "----" << std::endl;
    std::cout << result2 << std::endl;
    /*
     * eg "MDIC"
     * M at index 0, 1000
     * D at index 1, 500
     * I at index 2, 1
     * C at index 3, 100
     * First start with second last element, then compare with the last
     * loop till the front
     * Output:
     * i = 2, 1, 100
     * i = 1, 500, 1
     * i = 0, 1000, 500
     * 1599
     * ----
     * 100
     * */
    return 0;
}
