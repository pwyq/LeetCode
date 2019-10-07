// thanks soln
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // better brute force 
        // we only need to iterate up to sqrt(num), since there is always a counter part in (sqrt(num), num) for a divisor in (0, sqrt(num))
        // like 2 * 14
        // like 4 * 7
        
        if (num <= 0) return false;
        int sum = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i; // plus the counter part
                }
            }
        }
        return sum - num == num;
    }
};
