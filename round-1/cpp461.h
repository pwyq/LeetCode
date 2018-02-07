class Solution {
public:
    int hammingDistance(int x, int y) {
        int size = (x > y) ? x : y;
        int res = 0;
        while(size) {
            if((x%2) != (y%2)) res++;
            x = x/2;
            y = y/2;
            if (!x) {
                while(y) {
                    if (y%2)  res++;
                    y = y / 2;
                }
                return res;
            }
            if (!y) {
                while(x) {
                    if (x%2) res++;
                    x = x/2;
                }
                return res;
            }
        }
        return res;
    }
};

// Online solution
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};
