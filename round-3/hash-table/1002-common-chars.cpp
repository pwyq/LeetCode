// same in array
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        // This use the idea of hashmap, but we implement with vectors
        
        vector<int> cnt(26, INT_MAX);
        
        for (string word : A) {
            vector<int> temp(26, 0);
            for (char c : word) {
                temp[c-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                cnt[i] = min(cnt[i], temp[i]);
            }
        }
        
        vector<string> output;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                output.push_back(string(1, i+'a'));
            }
        }
        return output;
    }
};
