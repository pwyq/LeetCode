class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vs(26, 0);
        vector<int> vt(26, 0);
        for (char c : s)
            vs[c-'a']++;
        for (char c : t)
            vt[c-'a']++;
        
        bool res = true;
        for (int i = 0; i < 26; i++) {
            if (vs[i] != vt[i]) {
                res = false;
                break;
            }
        }
        return res;
    }
};
Runtime: 12 ms, faster than 81.14% of C++ online submissions for Valid Anagram.
Memory Usage: 9.7 MB, less than 35.82% of C++ online submissions for Valid Anagram.
