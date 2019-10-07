#include <string>
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        if (n == 0) return "";
        string res = "";
        int co = 0;
        int i = 0;
        while (co < n) {
            co = pow(26, i++);
        }
        i -= 1;
        cout << "n <= " << co << " | " << i << endl;
        while (i-- > 0) {
            int temp = n % 26;
            res += string(1, char(temp+'A'));
            n -= pow(26, i);
        }
        return res;
    }
};


int main() {
    for (int i = 0; i < 10; i++) {
        cout << pow(26, i) << " ";
    }
    cout << endl;
    cout << Solution().convertToTitle(0) << endl;
    cout << Solution().convertToTitle(1) << endl;
    cout << Solution().convertToTitle(2) << endl;
    cout << Solution().convertToTitle(28) << endl;
    cout << Solution().convertToTitle(26) << endl;
    cout << Solution().convertToTitle(701) << endl;
    return 0;
}
