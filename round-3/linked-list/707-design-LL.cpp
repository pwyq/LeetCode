// skipped
class MyLinkedList {
public:
    struct ListNode {
        ListNode *next;
        int val;
        ListNode(int a): next(NULL), val(a){}
    };
    ListNode *head;
    /** Initialize your data structure here. */
    MyLinkedList():head(NULL) {
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0)
            return -1;
        ListNode *curr = head;
        while(index-- > 0 && curr != NULL)
            curr = curr->next;
        if(curr != NULL)
            return curr->val;
        else
            return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        node->next = head;
        head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(head == NULL){
            addAtHead(val);
            return;
        }
        ListNode* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new ListNode(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index <= 0){
            addAtHead(val);
            return;
        }
        if(head == NULL)
            return;
        ListNode *curr = head;
        while(--index){
            if(curr->next == NULL)
                return;
            curr = curr->next;
        }
        
        ListNode *node = new ListNode(val);
        node->next = curr->next;
        curr->next = node;
    }
    void deleteHead(){
        if(head == NULL)
            return;
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(head == NULL)
            return;
        if(index == 0){
            deleteHead();
            return;
        }
        ListNode *curr = head, *tmp;
        while(--index){
            if(curr->next == NULL)
                return;
            curr = curr->next;
        }
        if(curr->next == NULL)
            return;
        tmp = curr->next->next;
        delete curr->next;
        curr->next = tmp;
    }
};