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
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* starting_pt = head;
      
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next; //2 se increasing
            slow = slow->next;
            
            if(slow == fast) //that means they converge at the same point and they have a cycle //collison
            {
                while(slow != starting_pt)
                {
                    slow = slow->next; //slow and next should meet at same point
                    starting_pt = starting_pt->next; 
                }
                
                //yaha pe mil jaayega
                 return starting_pt; //YEH TAB HO RAHA HAI JAB COLLISION HO RAHA HAI AND TABHI CYCLE HAI AND AGAR CYCLE HAI TABHI TOU HAMARA STARTING POINT HAI
            }
            
            //otherwise case agar collosion nahi hua tou return NULL that means there is no cycle
                
        }
        
        return NULL;
       
    }
    
};