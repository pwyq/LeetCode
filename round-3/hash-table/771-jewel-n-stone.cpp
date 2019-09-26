~6min

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> menu;

        for (auto str : S) {
            menu[str]++;
        }

        int res = 0;
        for (auto it = J.begin(); it != J.end(); it++) {
            res += menu[*it];
        }
        return res;
    }
};

//Runtime: 4 ms, faster than 65.10% of C++ online submissions for Jewels and Stones.
//Memory Usage: 8.7 MB, less than 26.25% of C++ online submissions for Jewels and Stones.
