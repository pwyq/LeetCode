#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;

// fuck my life, waste like 2 hours on this shit
// take a rest, this fucking easy problem shouldn't take that long
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cntlic(26, 0);
        for (auto ch : licensePlate) {
            if (isalpha(ch)) {
                ++cntlic[tolower(ch) - 'a'];
            }
        }
        
        int minL = INT_MAX;
        string res;
        for (auto& str : words) {
            vector<int> cnt(26, 0);
            for (auto ch : str) {
                ++cnt[ch - 'a'];
            }
            
            bool complete = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] < cntlic[i]) {
                    complete = false;
                    break;
                }
            }
            
            if (complete && str.length() < (size_t)minL) {
                res = str;
                minL = str.length();
            }
        }
        
        return res;
    }
};

int main() {
    vector<string> w = {"step", "steps", "stripe", "stepple"};
    string res = Solution().shortestCompletingWord("1s3 PSt", w);
    assert(res == "steps");

    vector<string> w2 = {"looks", "pest", "stew", "show"};
    string res2 = Solution().shortestCompletingWord("1s3 456", w2);
    assert(res2== "pest");

    vector<string> w3 = {"measure","other","every","base","according","level","meeting","none","marriage","rest"};
    string res3 = Solution().shortestCompletingWord("GrC8950", w3);
    assert(res3 == "according");

    vector<string> w4 = {"measure","other","every","acccrding","according","level","meeting","none","marriage","rest"};
    string res4 = Solution().shortestCompletingWord("GrC8950", w4);
    assert(res4 == "acccrding");


    vector<string> w5 = {"ten","two","better","talk","suddenly","stand","protect","collection","about","southern"};
    string res5 = Solution().shortestCompletingWord("TE73696", w5);
    assert(res5 == "ten");
    return 0;
}
