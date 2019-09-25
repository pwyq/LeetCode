class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // check 989
        // digits.resize(digits.size()+1);
        digits.insert(digits.begin(), 0);
        
        for (int i = digits.size()-1; i >= 0; i--) {
            if (i == digits.size()-1)
                digits[i]++;
            if (digits[i] >= 10) {
                digits[i] %= 10;
                digits[i-1]++;
            }
        }
        if (digits[0] == 0)
            digits.erase(digits.begin());
        
        return digits;
    }
};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
//Memory Usage: 8.8 MB, less than 22.95% of C++ online submissions for Plus One.
