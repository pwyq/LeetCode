class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (char c : s)
            m[c]++;
        
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

Runtime: 60 ms, faster than 50.46% of C++ online submissions for First Unique Character in a String.
Memory Usage: 13.1 MB, less than 35.94% of C++ online submissions for First Unique Character in a String.
