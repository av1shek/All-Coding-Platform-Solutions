/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int cc = 0;
        while (temp)
            temp = temp->next, cc++;
        if (cc < n)
            return head;
        if (cc == n)
            return head->next;
        temp = head;
        for (int i = 1; i < cc - n; ++i)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};