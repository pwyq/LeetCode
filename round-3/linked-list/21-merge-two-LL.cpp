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

/*
*/

class Solution {
public:
    // thanks dalao,
    // got stuck on this for 2 hours
    // I let head direclty points to the min of l1, l2,
    // which caused unsolvable inf loop later
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        ListNode* tail = &head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return head.next;
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
    ListNode* l1 = stringToListNode("[1,2,3]");
    ListNode* l2 = stringToListNode("[4,5,6]");
    ListNode* ret = Solution().mergeTwoLists(l1, l2);
    string out = listNodeToString(ret);
    assert(out=="[1, 2, 3, 4, 5, 6]");
    cout << out << endl;

    ListNode* l12 = stringToListNode("[1,2,3,7,8]");
    ListNode* l22 = stringToListNode("[4,5,6]");
    ListNode* ret2 = Solution().mergeTwoLists(l12, l22);
    string out2 = listNodeToString(ret2);
    assert(out2=="[1, 2, 3, 4, 5, 6, 7, 8]");
    cout << out2 << endl;

    ListNode* l13 = stringToListNode("[1,2,3]");
    ListNode* l23 = stringToListNode("[4,5,6,7,8]");
    ListNode* ret3 = Solution().mergeTwoLists(l13, l23);
    string out3 = listNodeToString(ret3);
    assert(out3=="[1, 2, 3, 4, 5, 6, 7, 8]");
    cout << out3 << endl;
    return 0;
}
