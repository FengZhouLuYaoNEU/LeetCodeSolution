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
    ListNode* reverseList(ListNode* head) {
        ListNode * stepNode = NULL;
        while (head)
        {
            ListNode * tmpNode = head->next; //store next node
            head->next = stepNode;          //link stepNode
            stepNode = head;                // setpNode move one step
            head = tmpNode;                //head move one step
        }
        return stepNode;
    }
};
// How to follow up?
