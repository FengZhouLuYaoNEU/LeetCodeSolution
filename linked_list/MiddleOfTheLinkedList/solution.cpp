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
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode * tmpHead = head;
        ListNode * retNode = NULL;
        while( head != NULL)
        {
            head = head->next;
            size++;
        }
        int middle = size / 2 + 1;
        for ( int i = 0; i < middle; ++i)
        {
            retNode = tmpHead;
            tmpHead = tmpHead->next;
        }
        return retNode;
    }
};
