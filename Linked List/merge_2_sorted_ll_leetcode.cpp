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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy_node = new ListNode(0); //not poiting to head
        ListNode* l3 = dummy_node;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)  //ascending order
            {
                l3->next = l1; //kyunki l3 initially null hai isiliye l3 ke next mai lagaya hai
                l1 = l1->next;
            }
            
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            
            l3 = l3->next;
        }
        
        //agar ek hi linked list di hogi tab ke cases
        if(l1 != NULL)
        {
            l3->next = l1;
            l3 = l3->next;
        }
        
        if(l2 != NULL)
        {
            l3->next = l2;
            l3 = l3->next;
        }
        
        return dummy_node->next; //we are returning dummy->next beacuse it was initially pointing to null
    }
};