Runtime: 4 ms, faster than 90.59% of C++ online submissions for Maximum Number of Balloons.
Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Maximum Number of Balloons.


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> balloon (5, 0);
        for (char c : text) {
            switch (c - 'a') {
                case 0:
                    balloon[0]++; break;
                case 1:
                    balloon[1]++; break;
                case 11:
                    balloon[2]++; break;
                case 13:
                    balloon[3]++; break;
                case 14:
                    balloon[4]++; break;
            }
        }

        int _min = INT_MAX;
        for (int i = 0; i < 5; i++) {
            if (i == 2 || i == 4)
                _min = std::min(_min, balloon[i] / 2);
            else
                _min = std::min(_min, balloon[i]);
        }
        return _min;
    }
};
