// Runtime: 16 ms, faster than 79.54% of C++ online submissions for X of a Kind in a Deck of Cards.
// Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for X of a Kind in a Deck of Cards.
//
//

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) return false;
        map<int, int> cnt;

        for (int i : deck)
            cnt[i]++;

        auto it = cnt.rbegin(); // reverse order

        int minSize = INT_MAX;
        while (it != cnt.rend()) {
            if (it->second < 2)
                return false;
            minSize = min(minSize, it->second);
            it++;
        }

        for (int i = 2; i <= minSize; i++) {
            it = cnt.rbegin();
            int c = 0;
            while(it != cnt.rend()) {
                if (it->second % i == 0)
                    c++;
                it++;
            }
            if (c == cnt.size())
                return true;
        }
        return false;
    }
};
// 1st failed [1,1,2,2,2,2]
// 2nd failed [1,1,1,1,2,2,2,2,2,2]
//
// FYI, C++ has built-in GCD (greatest common divisor)

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) count[i]++;
        for (auto i : count) res = __gcd(i.second, res);
        return res > 1;
    }
};
