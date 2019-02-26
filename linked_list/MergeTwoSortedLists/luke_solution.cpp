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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode*l3 = new ListNode(-1) ;
        ListNode*ll3 = l3;
        if(!l1)
        {
            return l2;
        }else if(!l2)
        {
            return l1;
        }
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        if(l1)
        {
            l3->next = l1;
        }
        if(l2)
        {
            l3->next = l2;
        }
        return ll3->next;
    }
};
