class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, char> m;
        for (int i = 0; i < t.length(); i++) {
            if (m.count(s[i]) == true) {
                if (m[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                char val = t[i];
                auto it = std::find_if(m.begin(), m.end(), [val](const auto& mo) {
                    return mo.second == val;
                });

                if(it != m.end())
                    return false;
                m[s[i]] = t[i];
            }
        }
        return true;
    }
};

// foo bar
// bar foo
// foobar barfoo
//
Runtime: 8 ms, faster than 86.68% of C++ online submissions for Isomorphic Strings.
Memory Usage: 9.2 MB, less than 72.00% of C++ online submissions for Isomorphic Strings.
