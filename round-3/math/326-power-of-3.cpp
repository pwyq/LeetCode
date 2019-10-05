class Solution {
public:
    bool isPowerOfThree(int n) {
        // std::fmod Computes the floating-point remainder of the division operation 
        return fmod(log10(n)/log10(3), 1)==0;
    }
};

// recursion
// Runtime: 20 ms, faster than 46.55% of C++ online submissions for Power of Three.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Power of Three.
