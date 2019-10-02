// the problem description is very unclear
// the problem essentially wants us to built a word one char a time using existing words with prefix fixed
// eg:
// "a" -> "ap"
// "ap" -> "app"
// "app" -> "appl"
// "appl" -> "apple"
// thanks dalao

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                cout << "w = " << w << endl;
                res = w.size() > res.size() ? w : res;
                built.insert(w);
            }
        }
        return res;
    }
};
