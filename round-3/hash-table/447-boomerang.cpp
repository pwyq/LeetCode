// thanks dalao for the equation
class Solution {
public:
    // fuck this problem description; does i < j?? otherwise, fuck the test cases
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int booms = 0;
        for (auto &p : points) {
            unordered_map<double, int> ctr(points.size());
            for (auto &q : points) {// since all are pairwise distinct, we don't have to worry about repeating itself
                // 2+4+6+8+...+2n = n(n+1)!
                booms += 2 * ctr[pow((p[0] - q[0]),2) + pow((p[1] - q[1]),2)]++;
            }
        }
        return booms;
    }
    
    
    /*
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // brute force
        unordered_map<float, int> m;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                cout << "i = " << i << ", j = " << j;
                float dist = calculateDist(points[i], points[j]);
                cout << ", " << dist << endl;
                m[dist]++;
            }
        }
        int sum = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            cout << it->first << " : " << it->second << endl;
            if (it->second >= 2)
                sum += factorial(it->second);
        }
        return sum;
    }
    
    int factorial(int n) { 
        return (n==1 || n==0) ? 1: n * factorial(n - 1);  
    }
    
    float calculateDist(vector<int> a, vector<int> b) {
        // try std::hypot
//         
        return sqrt(pow(a[0]-b[0],2)+pow(a[1]-b[1],2));
    }
    */
};
