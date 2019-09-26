// ~2min for idea ~45min for implementation
// haven't touched string manipulation for a long time...

Runtime: 16 ms, faster than 89.80% of C++ online submissions for Subdomain Visit Count.
Memory Usage: 13.5 MB, less than 46.67% of C++ online submissions for Subdomain Visit Count.

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& d) {
        unordered_map<string, int> m(0);
        
        for (string s : d) {
            auto s_pos = s.find(" ");
            int count = stoi(s.substr(0, s_pos));
            s = s.substr(s_pos+1, s.length()-1);
            m[s] += count;
            
            while (s.find(".") != string::npos) {
                s = s.substr(s.find(".")+1, s.length()-1);
                m[s] += count;
            }
        }
        
        vector<string> output;
        for (auto it = m.begin(); it != m.end(); it++) {
            string res = to_string(it->second) + " " + it->first;
            output.push_back(res);
        }
        
        return output;
    }
};
