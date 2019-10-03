// Thanks dalao!!!
/*
ListA = A + intersection
ListB = B + intersection
with this solution, it's like we concat ListA and ListB then find the intersection.
ListA+ListB = A + intersection + B +intersection
ListB + ListA = B + intersection + A + intersection
Then we can find the intersections.
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode *p1 = a;
        ListNode *p2 = b;
        
        while (p1 != p2) {
            p1 = p1 ? p1->next : b;
            p2 = p2 ? p2->next : a;
        }
        return p1;
    }
};
