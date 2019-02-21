#include <iostream>
using namespace std;

/*//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        ListNode* ll3 = new ListNode(0);
         ListNode* l3 = ll3;
         int temp =0;
         int bit =0;
        while(l1 != NULL || l2 != NULL || bit ==1)
        {
            //cout<<"enter while"<<endl;
            if(l1 != NULL && l2 != NULL)
            {
                temp = l1->val + l2->val+bit;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1 != NULL && l2 == NULL)
            {
                temp = l1->val+bit;
                l1 = l1->next;
            }else if(l1 == NULL && l2 != NULL)
            {
                temp = l2->val+bit;
                l2 = l2->next;
            }else
            {
                temp = bit;
            }
            ll3->next = new ListNode((temp)%10);
            ll3 = ll3->next;
            bit = 0;
            if(temp>9)
            {
                bit = 1;
            }

        }
        if(l3->next==NULL){
            l3->next=new ListNode(0);
        }
        
        return l3->next;
        
        
    }
};
