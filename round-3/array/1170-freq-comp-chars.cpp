class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> qu_freq = calculateFreq(queries);
        vector<int> wo_freq = calculateFreq(words);
        
        // print_vec(qu_freq);
        // print_vec(wo_freq);
        // std::sort(wo_freq.begin(), wo_freq.end());
        vector<int> res;
        for (int i = 0; i < qu_freq.size(); i++) {
            int th = qu_freq[i];
            int t = std::count_if(wo_freq.begin(), wo_freq.end(), [th](int n){return n > th;});
            res.push_back(t);
        }
        return res;
    }
    
    void print_vec(vector<int> a) {
        for (auto & i : a) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    
    vector<int> calculateFreq(vector<string>& a) {
        vector<int> res;
        
        for (auto & word : a) {
            vector<int> t(26, 0);
            for (auto & c: word) {
                t[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (t[i] != 0) {    // push the first founded, which is the min
                    res.push_back(t[i]);
                    break;
                }
            }
        }
        return res;
    }
};

/* Runtime: 52 ms, faster than 30.15% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
Memory Usage: 14.5 MB, less than 100.00% of C++ online submissions for Compare Strings by Frequency of the Smallest Character. */
