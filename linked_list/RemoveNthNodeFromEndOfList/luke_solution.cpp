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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* back = head;
        while(n--)
        {
           // if(front == NULL)     //len>n
           // {
           //    return NULL;
           // }
            front = front->next;
        }
        if(front == NULL)     //len = n
        {
            head = head->next;
            return head;
        }else                  //len<n
        {
            front = front->next;
        }
        while(front!=NULL)
        {
            front = front->next;
            back = back->next;
        }
        back->next = back->next->next;     //delete back->next
        return head;
    }
};
