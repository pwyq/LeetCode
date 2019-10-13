#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        // dalao solves in 44 seconds....
        int cnt=0;
        int sum=0;
        for(auto it:s){
            if(it=='R')sum++;
            else sum--;
            if(sum==0)cnt++;
        }
        return cnt;
        // int l = 0;
        // int r = 0;
        // int n = s.length();
        // int count = 0;
        // for (int i = 0; i < n; i++) {
        //     if (s[i] == 'L') {
        //         l++;
        //     }
        //     else {
        //         r++;
        //     }
        //     if (l == r) {
        //         l = 0;
        //         r = 0;
        //         count++;
        //     }
        // }
        // cout << "res = " << count << endl;
        // return count;
    }


};

int main() {
    assert(Solution().balancedStringSplit("RLRRLLRLRL")==4);
    assert(Solution().balancedStringSplit("RLLLLRRRLR")==3);
    assert(Solution().balancedStringSplit("LLLLRRRR")==1);
    assert(Solution().balancedStringSplit("L")==0);
    assert(Solution().balancedStringSplit("R")==0);

    return 0;
}
