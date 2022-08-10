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
    ListNode* reverseList(ListNode* head) 
    {
        //To reverse it, we need to invert the linking between nodes.
        // newNode <- 1 <- 2 <- 3 <- 4 <- 5 <- NULL
        //Set head as prevNode. This makes the head point at the last node.
        ListNode* prevNode = NULL;
        while(head != NULL)
        {
            ListNode* next = head->next; //kept next on head->next (2)
            head->next = prevNode; //pointing to prev node //break the connection then point to prev node 1->2 => break it 
            prevNode = head; //prev value head pe aa gayi
            head = next; //head aage badh gaya
            
        }
        //after all of this head points to the last node 
        //hence reverse done(main motive was to transfer the index from 1st node to last node and starting node has NULL)
        
        return prevNode;
    }
};