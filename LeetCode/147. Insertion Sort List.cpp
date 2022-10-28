class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        for(auto cur = head; cur; cur = cur -> next) 
            for(auto j = head; j != cur; j = j -> next) 
                if(j -> val > cur -> val) 
                    swap(j -> val, cur -> val); 
                    return head; 
    }
};