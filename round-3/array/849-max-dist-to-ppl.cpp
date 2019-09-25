// my idea is similar to dalao's, but his is more consice
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int n = seats.size();
        int last = -1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                res = (last < 0) ? i : max(res, (i-last)/2);
                last = i;
            }
        }
        return max(res, (n-1)-last);
    }
};

// first thought I need to find the index of the seat... waste a lot of time
