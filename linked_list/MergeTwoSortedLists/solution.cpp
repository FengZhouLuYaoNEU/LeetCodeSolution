//method 1
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
        vector<std::pair<int,ListNode*>> vec_pair;
        while (l1)
        {
            vec_pair.push_back(std::make_pair(l1->val,l1));
            l1 = l1->next;
        }
        while (l2)
        {
            vec_pair.push_back(std::make_pair(l2->val,l2));
            l2 = l2->next;
        }
        if (vec_pair.size() == 0)
        {
            return NULL;
        }
        std::sort(vec_pair.begin(), vec_pair.end(), [](std::pair<int,ListNode*> a, std::pair<int,ListNode*> b) {
          return std::get<0>(b) > std::get<0>(a);   
        });
        for (auto it = vec_pair.begin(); ; ++it)
        {
            auto next = it + 1;
            if (next == vec_pair.end())
            {
                break;
            }
            std::get<1>(*it)->next = std::get<1>(*next);
        }
        std::get<1>(*vec_pair.rbegin())->next =NULL;
        return std::get<1>(*vec_pair.begin());
    }
};
//optimize method 1
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<ListNode*> vec_node;
        while (l1)
        {
            vec_node.push_back(l1);
            l1 = l1->next;
        }
        while (l2)
        {
            vec_node.push_back(l2);
            l2 = l2->next;
        }
        if (vec_node.size() == 0)
        {
            return NULL;
        }
        
        std::sort(vec_node.begin(), vec_node.end(), [](ListNode* a, ListNode* b) {
          return a->val < b->val; 
        });
        
        for (size_t i = 0; i < vec_node.size() - 1; ++i)
        {
            vec_node[i]->next = vec_node[i + 1];
        }
        (*vec_node.rbegin())->next = NULL;
        return *vec_node.begin();
    }
