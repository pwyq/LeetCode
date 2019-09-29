// Not copied, read it last night, thanks to dalao for the idea
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mapping(26, 0);
        
        for (int i = 0; i < 26; i++) {
            mapping[order[i] - 'a'] = i;
        }
        
        for (string& word : words) {
            for (char& c : word) {
                c = char(mapping[c-'a'] + 'a');
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};
