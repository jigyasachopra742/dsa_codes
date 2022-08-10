#include <bits/stdc++.h>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
   int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return false;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
      
        
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next; //2 se increasing
            slow = slow->next;
            
            if(slow == fast) //that means they converge at the same point and they have a cycle
            {
                return true;
            }
                
        }
        
        
        return false;
    }
};