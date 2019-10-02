class Solution {
public:
    /* Alternative dalao's answer
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
    */
    vector<string> split(const string& str, const string& delim) {
        // same as 205
        vector<string> res;
        size_t prev = 0, pos = 0;
        do
        {
            pos = str.find(delim, prev);
            if (pos == string::npos) pos = str.length();
            string t = str.substr(prev, pos-prev);
            if (!t.empty()) res.push_back(t);
            prev = pos + delim.length();
        }
        while (pos < str.length() && prev < str.length());
        return res;
    }
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        vector<string> s = split(str, " ");
        if (pattern.length() != s.size()) return false;
        
        for (int i = 0; i < pattern.length(); i++) {
            if (m.count(pattern[i]) == true) {
                if (m[pattern[i]] != s[i])
                    return false;
            }
            else {
                string val = s[i];
                auto it = std::find_if(m.begin(), m.end(), [val](const auto& mo) {
                    return mo.second == val;
                });
                if (it != m.end()) return false;
                m[pattern[i]] = s[i];
            }
        }
        return true;
    }
};

Runtime: 4 ms, faster than 56.09% of C++ online submissions for Word Pattern.
Memory Usage: 8.7 MB, less than 85.71% of C++ online submissions for Word Pattern.
