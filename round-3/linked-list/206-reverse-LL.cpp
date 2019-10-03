/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        vector<int> temp;
        while (head != NULL) {
            temp.push_back(head->val);
            head = head->next;
        }
        if (temp.size() == 0) return head;
        
        int i = temp.size()-1;
        ListNode *h = new ListNode(temp[i]);
        ListNode *prev = h;
        ListNode *curr = h;
        while (--i < temp.size()) {
            curr = new ListNode(temp[i]);
            prev->next = curr;
            prev = curr;
        }
        return h;
    }
    /* some optimization..
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = NULL;
        while (head != NULL) {
            ListNode *next = head->next;
            head->next = curr;
            curr = head;
            head = next;
        }
        return curr;
    }
Runtime: 4 ms, faster than 98.91% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Reverse Linked List.
    */
};

Runtime: 12 ms, faster than 10.15% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.4 MB, less than 22.90% of C++ online submissions for Reverse Linked List.
