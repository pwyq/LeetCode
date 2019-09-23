class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // count character frequency
        
        std::map<char, int> freq;
        for (char &c : chars) {
            freq[c]++;
        }
        
        int res = 0;
        // for (int i = 0; i < words.size(); i++) {
        //     std::map<char, int> copy = freq;
        //     bool flag = true;
        //     for (int j = 0; j < words[i].size(); j++) {
        //         if (copy[words[i][j]] && copy[words[i][j]] > 0) {
        //             copy[words[i][j]]--;
        //         }
        //         else {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if (flag) {
        //         res += words[i].size();
        //     }
        // }
        // Runtime: 168 ms, faster than 21.85% of C++ online submissions for Find Words That Can Be Formed by Characters.
// Memory Usage: 56.9 MB, less than 100.00% of C++ online submissions for Find Words That Can Be Formed by Characters.
        for (string &str : words) {
            map<char, int> copy(freq);
            int count = 0;
            for (char &c : str) {
                if (copy[c]) {
                    count++;
                    copy[c]--;
                    if (count == str.size()) {
                        res += str.size();
                    }
                }
                else {
                    break;
                }
            }
        }
        return res;
        
        // Runtime: 168 ms, faster than 21.85% of C++ online submissions for Find Words That Can Be Formed by Characters.
// Memory Usage: 57.1 MB, less than 100.00% of C++ online submissions for Find Words That Can Be Formed by Characters.
    }
};
