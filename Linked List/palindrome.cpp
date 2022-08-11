#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list. */
  struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
       stack<int> st;
       ListNode* temp = head;
        
       while(temp != NULL)
       {
           st.push(temp->val);
           temp = temp->next;
       }
        
        //temp ko vapis se head pe rakh diya kyunki temp upar change ho gaya tha null pe tha
       temp = head; //to traverse through the linked lists
       while(temp != NULL)
       {
           if(temp->val == st.top()) //head se chalao aur check karo kya head is equal to value at top of stack
           {
               st.pop();
               temp = temp->next;
           }
           
           else
           {
               return false;
           }
           
       }
        
       return true;
    
        
       
        
    }
};