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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() == 0) return {};
        sort(deck.begin(), deck.end());// deck now is known deck

        vector<int> output_deck;

//        output_deck.push_back(deck[deck.size()-1]);
        while (deck.size() > 0) {
            if (output_deck.size() > 0) {                
                cout << "--------------------------- 1\n";
                print_vec(output_deck);
                print_vec(deck);
                int temp = output_deck[output_deck.size()-1];
                output_deck.insert(output_deck.begin(), temp);
                cout << "--------------------------- 1.5\n";
                print_vec(output_deck);
                print_vec(deck);
                output_deck.pop_back();
                cout << "--------------------------- 2\n";
                print_vec(output_deck);
                print_vec(deck);
            }

            output_deck.insert(output_deck.begin(), deck[deck.size()-1]);
            deck.pop_back();
            cout << "--------------------------- 3\n";
            print_vec(output_deck);
            print_vec(deck);
        }

        return output_deck;
    }

    void print_vec(vector<int> v) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    // vector<int> forwardHelper(vector<int> deck) {
    //     vector<int> a;
    //     while (deck.size() > 0) {
    //         a.push_back(deck[0]);
    //         deck.erase(deck.begin());
    //         int temp = deck[0];
    //         deck.push_back(temp);
    //         deck.erase(deck.begin());
    //     }
    //     return a;
    // }
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
        vector<int> deck = {17,13,11,2,3,5,7};

        vector<int> ret = Solution().deckRevealedIncreasing(deck);

        string out = integerVectorToString(ret);
        cout << out << endl;
    return 0;
}
