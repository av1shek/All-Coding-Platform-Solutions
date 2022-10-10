    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode newHead(0), *t;
        t = &newHead;
        while(l1 || l2)
        {
            if(!l2) { t->next = l1; break; }
            else if(!l1) { t->next = l2; break; }
            else if(l1->val < l2->val) 
            {
                t->next = l1;
                l1 = l1->next;
            }
            else
            {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        return newHead.next;
    }
