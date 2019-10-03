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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode h(-1);
        ListNode*curr = &h;
        
        while (head) {
            if (head->val == val) {
                curr->next = head->next;
                ListNode *temp = head;
                head = head->next;
                delete temp;
            }
            else {
                curr->next = head;
                head = head->next;
                curr = curr->next;
            }
        }
        return h.next;
    }
};

Runtime: 28 ms, faster than 66.22% of C++ online submissions for Remove Linked List Elements.
Memory Usage: 11.3 MB, less than 13.21% of C++ online submissions for Remove Linked List Elements.
