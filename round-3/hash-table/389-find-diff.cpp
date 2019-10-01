class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vs(26, 0);
        vector<int> vt(26, 0);
        for (char c : s)
            vs[c-'a']++;
        for (char c : t)
            vt[c-'a']++;
        
        char res;
        for (int i = 0; i < 26; i++) {
            if (vt[i] == vs[i]+1) {
                res = char(i + 'a');
            }
        }
        return res;
    }
};

Runtime: 4 ms, faster than 84.11% of C++ online submissions for Find the Difference.
Memory Usage: 9.1 MB, less than 55.56% of C++ online submissions for Find the Difference.
