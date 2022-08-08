#include<bits/stdc++.h>
using namespace std;

int maximumChocolates(vector<int> &arr, int k)
{
    //maximum number of chocolates
    priority_queue<int> pq; //max heap
    for(int idx = 0; idx < arr.size(); idx++)
    {
        pq.push(arr[idx]); 
    }
    
    int sum = 0;
    while(k--) //k > 0 //k = 1
    {
        int value = pq.top();//9
        sum+= value; //sum = 10 + 9 = 19
        
        pq.pop();
        pq.push(value/2);
      
        //[4,7,4,5] //[0,1,2,3]
        
    }
    
    return sum % (1000000007);
    // Write your code here.
}