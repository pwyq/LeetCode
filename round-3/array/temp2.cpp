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
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> t;
        print_map(t);
        for (int i = 0; i < nums.size(); i++) {
            cout << "i = " << i << endl;
            t.insert({nums[i], i});
            print_map(t);

            int diff = target - nums[i];
            auto it = t.find(diff);
            if (it != t.end()) {
                return {i, it->second};
            }
            else {
                cout << it->first << ", " << it->second << endl;
            }
        }
        return {0,0};
    }
    void print_map(map<int, int> y) {
        for (auto const& x : y)
        {
            std::cout << x.first  // string (key)
                      << ':'
                      << x.second // string's value
                      << std::endl ;
        }
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
