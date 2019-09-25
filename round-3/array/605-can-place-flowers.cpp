class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int available_slots = 0;
        int zero = 0;
        for (int i = 0; i < f.size(); i++) {
            if (f[i] == 0)
                zero += (i == 0) ? 2 : 1;
            else {
                int new_slots = (--zero % 2 == 0) ? (zero/2) : ((zero-1)/2);
                available_slots += (new_slots > 0) ? new_slots : 0;
                zero = 0;            
            }
        }
        
        if (zero > 0)
            available_slots += (zero % 2 == 0) ? (zero/2) : ((zero-1)/2);
        
        return (available_slots >= n);
    }
};

// Runtime: 12 ms, faster than 96.89% of C++ online submissions for Can Place Flowers.
// Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Can Place Flowers.
//
// I wrote a post :)
// https://leetcode.com/problems/can-place-flowers/discuss/390502/C%2B%2B-observing-math-sequences-beats-97Time-100Space


/* Deleted available_slots
class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int zero = 0;
        for (int i = 0; i < f.size(); i++) {
            if (f[i] == 0)
                zero += (i == 0) ? 2 : 1;
            else {
                int new_slots = (--zero % 2 == 0) ? (zero/2) : ((zero-1)/2);
                n -= (new_slots > 0) ? new_slots : 0;
                zero = 0;
            }
        }

        if (zero > 0)
            n -= (zero % 2 == 0) ? (zero/2) : ((zero-1)/2);

        return (n <= 0);
    }
};
*/
