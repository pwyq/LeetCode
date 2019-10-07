class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int len = s.length()-1;
        for (char c : s)
            res += (c-'A'+1)*pow(26,len--);
        return res;
    }
};

int main() {

}

// Runtime: 4 ms, faster than 70.91% of C++ online submissions for Excel Sheet Column Number.
// Memory Usage: 8.4 MB, less than 16.33% of C++ online submissions for Excel Sheet Column Number.
