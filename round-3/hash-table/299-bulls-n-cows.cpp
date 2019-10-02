#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

void print_map(unordered_map<char,int> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " : " << it->second  << endl;
    }
}
class Solution {
public:
    string getHint(string secret, string guess) {
        cout << "==================================\n";
        cout << "s = " << secret << ", g = " << guess << endl;
        // takes secret as base, guess.len may > sec.len
        unordered_map<char, int> nums;
        
        if (secret.length() != guess.length()) return "0A0B";
        int bull = 0;
        int cow = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            }
            else {
                // this part is smart
                if (nums[secret[i]]++ < 0) {
                    cow++;
                }
                if (nums[guess[i]]-- > 0) {
                    cow++;
                }
            }
        }
        print_map(nums);
        cout << "------------------\n";
        string res = to_string(bull) + "A" + to_string(cow) + "B";
        cout << "res = " << res << endl;
        return res;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string r1 = Solution().getHint("11231", "01111");
    assert(r1 == "2A1B");
    string r2 = Solution().getHint("1123", "01111");
    assert(r2 == "0A0B");
    string r3 = Solution().getHint("1807", "7810");
    assert(r3 == "1A3B");
    string r4 = Solution().getHint("1123", "0111");
    assert(r4 == "1A1B");
    return 0;
}
