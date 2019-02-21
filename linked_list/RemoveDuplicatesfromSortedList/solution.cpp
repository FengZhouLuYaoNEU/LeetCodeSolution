//method 1 ?
 struct Data
    {
      int val;
      ListNode* node;
      Data(int val_,ListNode* node_ ):val(val_),node(node_){};
      bool operator == (const Data & rhs) const
      {
          return this->val == rhs.val;
      }
      bool operator < (const Data & rhs) const
      {
          return this->val < rhs.val;
      }
    };
ListNode* deleteDuplicates2(ListNode* head) {
        set<Data> node_set;
        while(head)
        {
            Data  data(head->val,head);
            node_set.insert(data);
            head = head->next;
        }
        for (auto it = node_set.begin(); it != node_set.end() ;)
        {
            (it)->node->next = ((++it) == node_set.end()) ? NULL : (it)->node;
        }
        return (node_set.begin())->node;
    }


//method 2
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

    ListNode* deleteDuplicates(ListNode* head) {
       ListNode* tmpHead = head;
       if(head == NULL)
       {
           return NULL;
       }
       while(head->next)
       {
          if(head->val == head->next->val)
          {
            head->next = head->next->next;
          }
          else
          {
           head = head->next;
          }
       }
       return tmpHead;
    }
};
