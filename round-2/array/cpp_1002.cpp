// FUCK C++, it took me 5 min to get idea, and 90 min to implement + 20 min to debug
// FUCK all the stupid types, stupid APIs
// I am stupid

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        for (auto c : A[0]) {
            res.push_back(string(1, c));
        }
        // // store the 1st one as answer
        // // loop thru each word
        // //  compare each character with answer string
        // //      if matching, delete the matched one from comparing string
        // //      if not, delete the one from answer
        for (int i = 1; i < A.size(); i++) {
            int k = 0;
            for (int j = 0; j < A[i].size(); j++) {
                size_t found = A[i].find(res[k]);
                if (found != string::npos) {
                    // element found in word
                    A[i].at(found) = '.';
                    k++;
                }
                else {
                    // element not found in word
                    for (int i = 0; i < res.size(); i++) {
                        if (res[i] == res[k]) {
                            res.erase(res.begin()+k);
                            break;
                        }
                    }
                }
                if (k >= res.size()) {
                    break;
                }
            }
        }
        return res;
    }
};

// Runtime: 12 ms, faster than 94.94% of C++ online submissions for Find Common Characters.
// Memory Usage: 9.9 MB, less than 79.82% of C++ online submissions for Find Common Characters.

// ["bbddabab","cbcddbdd","bbcadcab","dabcacad","cddcacbc","ccbdbcba","cbddaccc","accdcdbb"]
// ["bella","label","roller"]
// ["cool","lock","cook"]
