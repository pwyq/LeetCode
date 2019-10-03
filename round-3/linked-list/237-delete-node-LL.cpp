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
    void deleteNode(ListNode* node) {
        if (node->next != NULL) {
            ListNode *next = node->next;
            *node = *next;              // let node points to what next points to
            delete next;
        }
    }
};
