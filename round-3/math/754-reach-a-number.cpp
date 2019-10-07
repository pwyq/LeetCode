#include <iostream>
#include <cmath>
#include <cassert>
#include <climits>
using namespace std;

// thanks dalao
// Step 0: Get positive target value (step to get negative target is the same as to get positive value due to symmetry).
// Step 1: Find the smallest step that the summation from 1 to step just exceeds or equalstarget.
// Step 2: Find the difference between sum and target. The goal is to get rid of the difference to reach target. 
    // For ith move, if we switch the right move to the left, the change in summation will be 2*i less. 
    // Now the difference between sum and target has to be an even number in order for the math to check out.
// Step 2.1: If the difference value is even, we can return the current step.
// Step 2.2: If the difference value is odd, we need to increase the step until the difference is even (at most 2 more steps needed).
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int step = 0;
        while (sum < target) {
            step++;
            sum += step;
        }
        while ((sum-target) % 2 != 0) {
            step++;
            sum += step;
        }
        return step;
    }
};
// class Solution {
// public:
//     // absolutely TLE
//     // int reachNumber(int target) {
//     //     return minSteps(target, 0, 0);
//     // }
    
//     // int minSteps(int target, int curr, int n) {
//     //     if (n >= 10) return n;
//     //     if (curr <= INT_MIN || curr >= INT_MAX) return n;
//     //     if (curr == target) return n;
//     //     n = n+1;
//     //     return min(minSteps(target, curr+n, n),
//     //                minSteps(target, curr-n, n));
//     // }
// };

int main() {
    int r1 = Solution().reachNumber(3);
    cout << r1 << endl;
    assert(r1 == 2);
    cout << "----------------------\n";
    int r2 = Solution().reachNumber(2);
    cout << r2 << endl;
    assert(r2 == 3);

    return 0;
}
