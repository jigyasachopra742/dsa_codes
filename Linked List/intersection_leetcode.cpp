#include <bits/stdc++.h>
using namespace std;

 /*Definition for singly-linked list.*/
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        ListNode* temp1 = headA; //for calculating size of list
        int count1 = 0;
        while(temp1 != NULL)
        {
            count1++; //length of headA list
            temp1 = temp1->next;
        }
        
        ListNode* temp2 = headB; //for calculating size of list
        int count2 = 0;
        while(temp2 != NULL)
        {
            count2++; //length of headB list
            temp2 = temp2->next;
        }
        
        //put both the pointers at head
        int gap = abs(count1 - count2); 
        if(count1 > count2)
        {
            for(int idx = 0; idx < gap; idx++)
            {
                ptr1 = ptr1->next;
            }
        }
        
        else
        {
            for(int idx = 0; idx < gap; idx++)
            {
                ptr2 = ptr2->next;
            }
        }
        
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1;
    
    }
};