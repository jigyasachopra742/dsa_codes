#include <iostream>
#include <queue>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class MedianPriorityQueue {
    
    public:
    
    priority_queue <int> left;  //max heap
    priority_queue <int, vector<int>, greater<int>> right;  //min heap
    
    void push(int val) { //for adding ele in left pq and right pq
       
       if (right.empty() || val < right.top()) 
       {
           left.push(val); //adding in left pq //by default add in left pq
       }
       
       else 
       {
           right.push(val); //adding in right pq
       }
       
        int l = left.size();
        int r = right.size();
        
        if (abs(l - r) > 1) 
        {
            
            if (left.size() > right.size()) 
            {
                right.push(left.top()); //topmost ele 
                left.pop();
            }
            
            else 
            {
                left.push(right.top()); //topmost ele
                right.pop();
            }
        }
    }
    /*
    The elements are added by default to the left priority queue.
The difference between the size of the two priority queues should be maintained to 1. If the difference increases, shift one element from the queue with higher no of elements to the one with the lower.
If the input element is greater than the value of peek() of the right priority queue, then it is added to the right priority queue only.
    */
    int pop() 
    {
        if (left.empty() && right.empty()) 
        {
            cout<<"Underflow"<<endl;
            return -1;
        }
        
        else 
        {
            
            int ans;

            if (left.size() >= right.size()) 
            {    
                ans = left.top();
                left.pop();
            }
            
            else 
            {  
                ans = right.top();
                right.pop();
            }
            
            //adjusting if diff becomes greater than 1, is not reqd coz if size
            //of left right equal then removeing 1 element does not make diff 
            //greater than 1, and otherwise element is removing from greater sized
            //queue so after removal will make size equal of both queue.
            return ans;
        }
    }
    //If the number of elements are equal for both the priority queues, we remove from the left else we remove from the priority queue which has more number of elements

    int top() 
    {
        if (left.empty() && right.empty()) 
        {
            cout<<"Underflow"<<endl;
            return -1;
        }
        
        else 
        {
            if (left.size() >= right.size()) 
            {    
                return left.top(); //peeek the topomost ele 
                //vahi median hoga pq ka
            }
            
            else 
            {  
                return right.top(); //median of pq
            }
        }
    }
    
    //If there are even numbers of elements then the median is the peek() of the left priority queue, else if there are odd numbers of elements, the median is the peek() of the queue with more elements.

    int size() {
        return left.size() + right.size();
    }
};

int main() {
    MedianPriorityQueue pq;
    
    string str;
    cin >> str;
    while(str!="quit"){
        if(str=="add"){
            int val;
            cin >> val;
            pq.push(val);
        }
        else if(str=="remove"){
            int val = pq.pop();
            if(val != -1) {
                cout<<val<<endl;
            }
        }
        else if(str=="peek"){
            int val = pq.top();
            if(val != -1) {
                cout<<val<<endl;
            }
        }
        else if(str=="size"){
            cout<<pq.size()<<endl;
        }
        cin >> str;
    }
    return 0;
}