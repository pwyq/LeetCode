#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // this looks like a variant of the water-holding problem from TU Delft CG Lab1
        
        // vector<int> diffs;
        int size = prices.size();
        int cnt = 0;
        for (int i = 1; i < size; i++) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) {
                cnt += diff;
            }
        }
        return cnt;
        /*
        int size = prices.size();
        vector<int> l(size, 0);
        vector<int> r(size, 0);
        
        cout << "size = " << size << endl;
        
        int l_min = prices[0];
        l[0] = l_min;
        for (int i = 1; i < size; i++) {
            if (l_min > prices[i]) {
                l_min = prices[i];                
            }
            l[i] = l_min;
        }
        
        int r_max = prices[size-1];
        r[size-1] = r_max;
        for (int i = size-2; i >= 0; i--) {
            if (r_max < prices[i]) {
                r_max = prices[i];                
            }
            r[i] = r_max;
        }
        
        vector<int> buy;
        for (int i = 0; i < size; i++) {
            int diff = r[i] - l[i];
            cout << "on day " << i << ", buy = " << l[i] << ", sell = " << r[i] << endl;
            if (diff > 0)
                buy.push_back(diff);
        }

        return std::accumulate(buy.begin(), buy.end(), 0);
        */
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
        vector<int> prices = {7,1,5,3,6,4,7,6,4,3,1};
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    return 0;
}
