// ~10min, did it 3 days ago
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> m;
        for (char c : chars)
            m[c]++;
        
        int res = 0;
        unordered_map<char, int> copy(m);
        for (int i = 0; i < words.size(); i++) {
            auto it = words[i].begin();
            for (; it != words[i].end(); it++) {
                if (--copy[*it] < 0) break;
            }
            if (it == words[i].end())
                res += words[i].length();
            copy = m;
        }
        return res;
    }
};

// Runtime: 88 ms, faster than 46.82% of C++ online submissions for Find Words That Can Be Formed by Characters.
// Memory Usage: 17.5 MB, less than 100.00% of C++ online submissions for Find Words That Can Be Formed by Characters.
