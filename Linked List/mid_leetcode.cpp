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

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        //fast and slow
        //keep fast 2 steps forward from slow pointer
        //floyd's algo
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) //Because it is 2 steps forward
        {
            slow = slow->next;
            fast = fast->next->next; //2 steps further
            
        }
        
        return slow; //node which is the middle not t
    }
};