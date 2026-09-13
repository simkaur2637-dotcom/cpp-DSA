//Q 141 
//**********list sycle******
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow = head;
        ListNode*fast = head;

        while( fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if( slow == fast){
                return true;
            }
        }
        return false;
    }
};

//Q876
//********MIDDLE OF THE LINKED LIST****
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head;
        while( fast != nullptr && fast->next !=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


//Q 19
//******Remove Nth Node From End of List****
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy = new ListNode(0);
        dummy->next = head;

        ListNode*slow = dummy;
        ListNode*fast = dummy;

        for ( int i=0; i<=n ; i++){
            fast = fast->next;
        }
        while( fast != nullptr){
            slow = slow->next;
            fast = fast->next;
}
        ListNode*DeleteNode = slow->next;
    slow->next = slow->next->next;
    delete DeleteNode;

    ListNode*NewHead = dummy->next;
    delete dummy;
    return NewHead;
        
    }
    
};



