#include<bits/stdc++.h> 
using namespace std; 

 /* Definition for singly-linked list.*/
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution 
{
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        
        ListNode* dummy_head = new ListNode(0);
        
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        
        ListNode* curr = dummy_head;
        
        int carry = 0;
        
        while(ptr1 != NULL || ptr2 != NULL || carry != 0)
        {
            int fele = (ptr1 != NULL) ? ptr1->val : 0;
            int sele = (ptr2 != NULL) ? ptr2->val : 0;
            
            int sum = fele + sele + carry;
           
            carry = sum / 10; //always 1
            
            curr->next = new ListNode(sum % 10); //jo aayega usko answer mai(dummmy node curr) //dummy node will be pointing to that node in new ll
            curr = curr->next;
            
            if(ptr1 != NULL)
            {
                ptr1 = ptr1->next;
            }
            
            if(ptr2 != NULL)
            {
                ptr2 = ptr2->next;
            }
        }
        
        if(carry > 0)
        {
            curr->next = new ListNode(carry); //by chance li and l2 becomes empty but we add carry in answer(normal addition)
        }
        
        return dummy_head->next; //dummy was initially 0 hence next should be returned
    }
};