// thanks dalao
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0) return 1;
        int number_of_bits = floor(log2(n))+1;
        int what = (1 << number_of_bits) - 1;   // use this to create a 0111111...111 mask!!!!
        return (what) ^ n;
    }
};
