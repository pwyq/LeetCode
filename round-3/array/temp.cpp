#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        int longest = -1;
        for (int i = 0; i < nums.size(); i++) {
            int start = i;
            while (nums[i+1] > nums[i]) {
                if ((i-start) > longest)
                    longest = i-start;
                i++;
            }
        }
        return longest+1;
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
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().findLengthOfLCIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
