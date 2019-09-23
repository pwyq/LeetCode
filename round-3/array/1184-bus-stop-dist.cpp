class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dist, int start, int dest) {
        if (start == dest) return 0;
        int sum = std::accumulate(dist.begin(), dist.end(), 0);
        
        int r1 = 0;
        if (start < dest) {
            for (int i = start; i < dest; i++) {
                r1 += dist[i];
            }
        }
        else {
            for (int i = dest; i < start; i++) {
                r1 += dist[i];
            }
        }
        int r2 = sum - r1;
        return min(r1, r2);
        
    }
};

/*
 * Runtime: 4 ms, faster than 96.05% of C++ online submissions for Distance Between Bus Stops.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Distance Between Bus Stops.*/
