class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> cnt;
        
        int res = 0;
        for (auto &d : dominoes) {
            if (d[0] > d[1])
                swap(d[0], d[1]);
            cnt[d]++;
            if (cnt[d] > 1)
                res += (cnt[d]-1);
        }
        return res;
    }
};

/*Runtime: 68 ms, faster than 15.18% of C++ online submissions for Number of Equivalent Domino Pairs.
Memory Usage: 21.1 MB, less than 100.00% of C++ online submissions for Number of Equivalent Domino Pairs.*/



/*Runtime: 44 ms, faster than 74.61% of C++ online submissions for Number of Equivalent Domino Pairs.
Memory Usage: 21 MB, less than 100.00% of C++ online submissions for Number of Equivalent Domino Pairs.*/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int res = 0;
        for (auto& d : dominoes) {
            res += count[min(d[0], d[1]) * 10 + max(d[0], d[1])]++; // convert pair to double-digit number
        }
        return res;
    }
};
