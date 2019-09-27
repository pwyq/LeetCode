// waste some time on trying to compare words between two strings, then I observed the pattern
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Uncommon Words from Two Sentences.
Memory Usage: 9.4 MB, less than 12.50% of C++ online submissions for Uncommon Words from Two Sentences.

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        // We observe that for C=A+B
        // if any words appear twice in C, meaning is common; otherwise, we shall record it
        
        unordered_map<string, int> mm;
        string C = A + " " + B;
        mm = helper(C, ' ');
        
        vector<string> res;
        for (auto it = mm.begin(); it != mm.end(); it++) {
            if (it->second == 1 && it->first != "") {
                res.push_back(it->first);
            }
        }
        return res;
    }
    
    unordered_map<string, int> helper(const std::string &txt, char ch)
    {
        vector<string> res;
        size_t pos = txt.find( ch );
        size_t initialPos = 0;

        while( pos != std::string::npos ) {
            res.push_back( txt.substr( initialPos, pos - initialPos ) );
            initialPos = pos + 1;

            pos = txt.find( ch, initialPos );
        }

        res.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );
        
        unordered_map<string, int> m;
        for (string s : res)
            m[s]++;
            

        return m;
    }
};
