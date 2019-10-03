class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            bool isTrue = true;
            int temp = i;
            while (temp > 0) {
                int digit = temp % 10;
                if (digit == 0) {
                    isTrue = false;
                    break;
                }
                if (i % digit != 0) {
                    isTrue = false;
                    break;
                }
                temp = temp / 10;
            }
            if (isTrue) {
                res.push_back(i);
            }
        }
        return res;
    }
};

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Self Dividing Numbers.
Memory Usage: 8.4 MB, less than 88.00% of C++ online submissions for Self Dividing Numbers.
