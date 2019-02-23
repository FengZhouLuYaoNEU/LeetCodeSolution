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
    ListNode* swapPairs(ListNode* head) {
        vector<ListNode*> vec_list;
        while (head)
        {
           vec_list.push_back(head);
            head = head->next;
        }
        if (vec_list.size() == 0)
        {
            return NULL;
        }
        if (vec_list.size() == 1)
        {
            return *vec_list.begin();
        }
        for (size_t i = 0; i < vec_list.size(); i = i + 2)
        {
            if (i + 1 >= vec_list.size())
            {
                break;
            }
            ListNode * tmp = vec_list[i];
            vec_list[i] = vec_list[i + 1];
            vec_list[i + 1] = tmp;
        }
        for (size_t i = 0; i< vec_list.size() - 1; ++i)
        {
            vec_list[i]->next = vec_list[i+1];
        }
        (*vec_list.rbegin())->next = NULL;
        return *vec_list.begin();
    }
};

// solution not use vector ?



