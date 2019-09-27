// 5 wrong subs..., 70 min+
// Important to realize there is an upper limit!!
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
//         int sis = 0;
//         unordered_map<int, int> m;
//         for (int i : candies)
//             m[i]++;
//         int limit = candies.size() / 2;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             if (++sis > limit) break;
//         }
//         return (sis > limit) ? limit : sis;
// Runtime: 304 ms, faster than 54.37% of C++ online submissions for Distribute Candies.
// Memory Usage: 50.7 MB, less than 66.67% of C++ online submissions for Distribute Candies.
        set<int> kinds;
        int n = candies.size() / 2;         // limit
        for (int i = 0; i < candies.size(); i++) {
            if (kinds.size() + 1 > n) break;
            kinds.insert(candies[i]);
        }
        return kinds.size();
        
// Runtime: 328 ms, faster than 36.54% of C++ online submissions for Distribute Candies.
// Memory Usage: 41.4 MB, less than 66.67% of C++ online submissions for Distribute Candies.
    }
};

// [1000,1000,2,1,2,5,3,1]
// [1000, 1, 1, 1]
