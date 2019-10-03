#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_LL(ListNode* l) {
    while (l != NULL) {
        cout << l->val << "->";
        l = l->next;
    }
    cout << endl;
}

// Runtime: 12 ms, faster than 71.87% of C++ online submissions for Remove Duplicates from Sorted List.
// Memory Usage: 9.3 MB, less than 71.70% of C++ online submissions for Remove Duplicates from Sorted List.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode * temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else {
                curr = curr->next;
            }
        }
        return head;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    ListNode* l1 = stringToListNode("[1,1,1,2]");
    ListNode* ret = Solution().deleteDuplicates(l1);
    string out = listNodeToString(ret);
    cout << out << endl;
    assert(out=="[1, 2]");

    ListNode* l2 = stringToListNode("[1,1,1,2,2,2,2,2,2,2,2,3,4,5,5,5,6]");
    ListNode* ret2 = Solution().deleteDuplicates(l2);
    string out2 = listNodeToString(ret2);
    cout << out2 << endl;
    assert(out2=="[1, 2, 3, 4, 5, 6]");
    return 0;
}
