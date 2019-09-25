#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <climits>
#include <map>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (target < nums[0]) return 0;
        if (target > nums[n-1]) return n;
        
        int res = -1;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == target) return i;
            if (nums[i] <= target && target <= nums[i+1])
                res = i+1;
        }
        return res;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().searchInsert(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
