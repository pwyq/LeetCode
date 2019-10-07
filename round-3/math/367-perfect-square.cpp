class Solution {
public:
    bool isPerfectSquare(int num) {
// 1 = 1
// 4 = 1 + 3
// 9 = 1 + 3 + 5
// 16 = 1 + 3 + 5 + 7
// 25 = 1 + 3 + 5 + 7 + 9
// 36 = 1 + 3 + 5 + 7 + 9 + 11
// ....
// so 1+3+...+(2n-1) = (2n-1 + 1)n/2 = n*n

    // Sqrt(n) soln
     int i = 1;
     while (num > 0) {
         num -= i;
         i += 2;
     }
     return num == 0;

     // logn soln (overflow possible)
    // int low = 1;
    // int high = num;
    // while (low <= high) {
    //     int mid = low + (high - low)/2;
    //     if (mid * mid == num) {
    //         return true;
    //     } else if (mid * mid < num) {
    //         low = (int) mid + 1;
    //     } else {
    //         high = (int) mid - 1;
    //     }
    // }
    // return false;
    }
};
