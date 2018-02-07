/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Mine didn't got accepted due to the digit limit when
// adding num1 and num2.
// I personally think the method is work-able, though very inefficient

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0;
        int multiple1 = 1;
        if (l1 || l1->val == 0) {
            while (l1->next != NULL) {
                num1 += multiple1 * (l1->val);
                multiple1 *= 10;
                l1 = l1->next;
            } 
            if (l1->val)
                num1 += multiple1 * (l1->val);
        }
        int num2 = 0;
        int multiple2 = 1;
        if (l2 || l2->val == 0) {            
            while (l2->next != NULL) {
                num2 += multiple2 * (l2->val);
                multiple2 *= 10;
                l2 = l2->next;
            }
            if (l2->val)
                num2 += multiple2 * (l2->val);
        }
        int res = num1 + num2;
        if (res == 0) { return (new ListNode(0)); }
        ListNode l3(0), *p = &l3;
        while (res) {
            p->next = new ListNode(res % 10);
            res = res / 10;
            p = p->next;
        }
        return l3.next;
    }
};

// Accepted answer from online

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};
