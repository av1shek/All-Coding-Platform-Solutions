// Problem statement: check if the linked list is palindrome or not

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head,*fast=head,*prev, *temp;
        //FINDING MIDDLE NODE
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
     // REVERSING ELEMENTS AFTER MIDDLE NODE
        prev = slow;
        slow= slow->next;
        prev->next = NULL;
        while(slow){
            temp= slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        // COMPARING FROM TWO ENDS
        fast = head;
        slow = prev;
        while(slow){
            if(fast->val!=slow->val){
                return false;
            }
            else{
                fast = fast->next;
                slow = slow->next;
            }
        }
        return true;
    }
};