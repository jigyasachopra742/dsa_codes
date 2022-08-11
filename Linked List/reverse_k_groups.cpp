#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list. */
  struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        //count the length of ll
        if(head == NULL || k == 1)
        {
            return head; //agar k = 1 hai matlab koi group ban hi nah raha, as it is hai
        }
        //toughest to understand
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy, *pre = dummy, *nex = dummy;
        
        int count = 0;
        
        while(curr->next != NULL)
        {
            curr = curr->next;
            count++; //for finding length of ll
        }
        
        //curr is always the first node in a group
        //nex is always the second node in a group
        
        while(count >= k)
        {
            curr = pre->next; //1st node in every k group //curr = 1
            //curr->next = 1 ka next is 2
            nex = curr->next; //2nd node in every k group //nex = 2
            for(int idx = 1; idx < k; idx++)
            {
                curr->next = nex->next; //1->3
                nex->next = pre->next; //2->1
                
                 pre->next = nex; //pre->next = 2
                nex = curr->next; //nex = 3
               
            }
            
            pre = curr; //last mai 1
            count-=k;
            
        }
        
        return dummy->next;
        
        
        
    }
};