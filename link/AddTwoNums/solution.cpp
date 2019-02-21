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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        if (l1 == NULL && l2)
        {
            return l2;
        }
        if (l1 && l2 == NULL)
        {
            return l1;
        }
        int carryBit = 0;
        std::vector<int> vi;
        while (l1 || l2 || carryBit == 1)
        {
            Ret ret = add(l1,l2,carryBit);
            if (ret.isCarryBit)
            {
                carryBit = 1;
            }
            else
            {
                carryBit = 0;
            }
                        
            if (l1 && l1->next)
            {
                l1 = l1->next;
            }
            else
            {
                l1 = NULL;
            }
            if (l2 && l2->next)
            {
                l2 = l2->next;
            }
            else
            {
                l2 = NULL;
            }
            vi.push_back(ret.retVal);         
        }
        ListNode* head = NULL;
        for (std::vector<int>::reverse_iterator it = vi.rbegin(); it != vi.rend(); it++)
        {
          ListNode * p = new ListNode(*it);
          p->next = head;
          head = p;
        }
        return head;
    }
private:
    struct Ret
    {
        bool isCarryBit;
        int  retVal;
        Ret():isCarryBit(false){}
    };
    Ret add(ListNode* l1, ListNode* l2, int carryBit)
    {
        Ret ret;
        if (l1 == NULL && l2 == NULL && carryBit)
        {
            ret.retVal = 1;
        }
        if (l1 == NULL && l2)
        {
            ret.retVal = l2->val + carryBit;
            if (ret.retVal >= 10)
            {
                ret.retVal = 0;
                ret.isCarryBit = true;
            }
        }
        if (l1 && l2 == NULL)
        {
            ret.retVal = l1->val + carryBit;
            if (ret.retVal >= 10)
            {
                ret.retVal = 0;
                ret.isCarryBit = true;
            }
        }
        if (l1 != NULL && l2 != NULL)
        {
           if (l1->val + l2->val + carryBit >= 10)
           {
            ret.retVal = (l1->val + l2->val + carryBit)%10;
            ret.isCarryBit = true;
           }
           else
           {
                ret.retVal = l1->val + l2->val + carryBit;
           }
          
        }   
        return ret;
    }
};
