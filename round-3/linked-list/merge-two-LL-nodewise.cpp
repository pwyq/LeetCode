#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cassert>
// I didn't read the problem carefully, and implement following (Z-shape concatenating)
// eg
// a->b->c->d
// e->f->g
// result: a->e->b->f->c->g->d
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

/* STEP BY STEP!
1->2->3
4->5->6

head=l1;

curr = l1=1->2->3
next = l2=4->5->6
l1 = l1->next; l1=2->3
l2 = l2->next; l2=5->6
curr->next = next;

head->1->4->5->6
next->next = l1
head->1->4->2->3

curr = l1=2->3
next = l2=5->6

l1 = l1->next; l1 = 3
l2 = l2->next; l2 = 6

curr_next = next
head->1_>4_>2->5->6
next->next = l1
head->1->4->2->5->3

l1 = l1->next; l1=NULL
l2 = l2->next; l2=NULL

curr = l1=3
next = l2=6
curr->next = next
head->1->4->2->5->3->6
next->next = NULL
head->1-4->2->5->3->6->NULL

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode *curr, *next = NULL;
        while (l1 != NULL && l2 != NULL) {
            curr = l1;
            next = l2;
            l1 = l1->next;
            l2 = l2->next;
            curr->next = next;
            next->next = l1;
            print_LL(head);
        }
        cout << "stopped!\n";
        print_LL(head);
        if (l1 == NULL && l2 != NULL) {
            ListNode* tail = head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = l2;
            print_LL(tail);
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
    ListNode* l1 = stringToListNode("[1,2,3]");
    ListNode* l2 = stringToListNode("[4,5,6]");
    ListNode* ret = Solution().mergeTwoLists(l1, l2);
    string out = listNodeToString(ret);
    assert(out=="[1, 4, 2, 5, 3, 6]");
    cout << out << endl;

    ListNode* l12 = stringToListNode("[1,2,3,7,8]");
    ListNode* l22 = stringToListNode("[4,5,6]");
    ListNode* ret2 = Solution().mergeTwoLists(l12, l22);
    string out2 = listNodeToString(ret2);
    assert(out2=="[1, 4, 2, 5, 3, 6, 7, 8]");
    cout << out2 << endl;

    ListNode* l13 = stringToListNode("[1,2,3]");
    ListNode* l23 = stringToListNode("[4,5,6,7,8]");
    ListNode* ret3 = Solution().mergeTwoLists(l13, l23);
    string out3 = listNodeToString(ret3);
    assert(out3=="[1, 4, 2, 5, 3, 6, 7, 8]");
    cout << out3 << endl;
    return 0;
}
