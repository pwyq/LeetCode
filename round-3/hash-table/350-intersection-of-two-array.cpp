// thanks dalao
class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
        // auto i = std::set_intersection(a.begin(), a.end(), b.begin(), b.end(),a.begin());   // looks like this will return the (first unmatched index + 1) of a
        return a;
    }
};
