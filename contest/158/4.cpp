#include <unordered_map>
#include <string>
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            cout << "nums[i] = " << nums[i] << endl;
            m[nums[i]]++;
            std::unordered_map<int, int>::iterator best = std::max_element(m.begin(),m.end(),[] (const std::pair<int,int>& a, const std::pair<int,int>& b)->bool{ return a.second < b.second; } );
            std::unordered_map<int, int>::iterator worst = std::max_element(m.begin(),m.end(),[] (const std::pair<int,int>& a, const std::pair<int,int>& b)->bool{ return a.second > b.second; } );

            bool test = removeone(m, best->first, best->second);
            bool test2 = removetwo(m, worst->first, worst->second);
            if (test == true || test2)
                res = i+1;
        }
        cout << "res = " << res << endl;
        return res;
    }

    bool removeone(unordered_map<int, int> m, int best_num, int best_occ) {
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->first == best_num) continue;
            if (it->second != best_occ-1) return false;
        }
        return true;
    }

    bool removetwo(unordered_map<int, int> m, int best_num, int best_occ) {
        int n = -1;
        bool nnnn = false;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->first == best_num) continue;
            if (nnnn == false)
                n = it->second;
            if (it->second != n) return false;
        }
        return true;
    }
};

int main() {
    vector<int> n1 = {2,2,1,1,5,3,3,5};
    assert(Solution().maxEqualFreq(n1)==7);
}
