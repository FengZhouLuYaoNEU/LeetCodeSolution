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
        std::unordered_map<int,ListNode*> node_map;
        int key = 0;
        ListNode* tmp = head;
        while(tmp)
        {
            node_map[key++] = tmp;
            tmp = tmp->next;
        }
        if (n == 1 && key == 1)
        {
            delete node_map[key - 1];
            node_map[key - 1] = NULL;
            return head = NULL;
        }
        else if (n == 1)
        {
            delete node_map[key - 1];
            node_map[key - 1] = NULL;
            node_map[key - 2]->next = NULL;
            return head;
        }
        else if (n == key)
        {
           delete node_map[0];
           node_map[0] = NULL;
           return head = node_map[1];  
        }
        int del = key - n;
        delete node_map[del];
        node_map[del] = NULL;
        node_map[del - 1]->next = node_map[del + 1];
        return head;
        
    }
};
