// 1 submission
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        unordered_map<char, int> row1;
        string string1 = "qwertyuiopQWERTYUIOP";
        for (auto it = string1.begin(); it != string1.end(); it++) {
            row1[*it]++;
        }
        
        unordered_map<char, int> row2;
        string string2 = "asdfghjklASDFGHJKL";
        for (auto it = string2.begin(); it != string2.end(); it++) {
            row2[*it]++;
        }
        
        unordered_map<char, int> row3;
        string string3 = "zxcvbnmZXCVBNM";
        for (auto it = string3.begin(); it != string3.end(); it++) {
            row3[*it]++;
        }
        
        vector<string> res;
        for (string w : words) {
            char determineRow = w[0];
            bool isGood = true;
            if (string1.find(w[0]) != string::npos) {
                for (char c : w) {
                    if (row1[c] != 1) {
                        isGood = false;
                        break;
                    }
                }
            }
            else if (string2.find(w[0]) != string::npos) {
                for (char c : w) {
                    if (row2[c] != 1) {
                        isGood = false;
                        break;
                    }
                }
                
            }
            else if (string3.find(w[0]) != string::npos) {
                for (char c : w) {
                    if (row3[c] != 1) {
                        isGood = false;
                        break;
                    }
                }
            }
            if (isGood) res.push_back(w);
        }
        return res;
    }
};
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Keyboard Row.
Memory Usage: 8.7 MB, less than 14.29% of C++ online submissions for Keyboard Row.
