// Other approaches
// check Floyd Cycle detection algorithm
// https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)

class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        vector<int> cycles = {4,16,37,58,89,145,42,20};    // set for faster search time O(logn), vector has O(n) search time
        // but our cycles.size is small here, so we use vector
        // Use math property here; wiki search "Happy Number" for base-10 numbers
        while (find(cycles.begin(), cycles.end(), n) == cycles.end()) {
            n = digitSquareSum(n);
            if (n == 1) return true;
        }
        return false;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
// Memory Usage: 8.2 MB, less than 96.15% of C++ online submissions for Happy Number.
