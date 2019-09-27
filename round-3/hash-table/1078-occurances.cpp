// ~10min
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> splited;
        splited = split(text, ' ');

        vector<string> res;
        for (int i = 1; i < splited.size() -1; i++) {
            if (splited[i-1] == first && splited[i] == second) {
                res.push_back(splited[i+1]);
            }
        }
        return res;
    }
    
    
    vector<string> split(const std::string &txt, char ch)
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

        return res;
    }
};

/*Runtime: 4 ms, faster than 57.95% of C++ online submissions for Occurrences After Bigram.
Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Occurrences After Bigram.*/
