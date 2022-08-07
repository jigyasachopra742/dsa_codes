#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
        //vahi 2 ropes lo jinka size min ho
        //The cost to connect two ropes is equal to sum of their lengths(acc to ques)
        long long cost = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq; //min heap //as we want the smallest
        
        for(int idx = 0 ; idx < n; idx++)
        {
            pq.push(arr[idx]); //pushing the array ele in min heap
        }
        
        while(pq.size() >= 2)//The cost to connect two ropes is equal to sum of their lengths(acc to ques)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            cost+= first + second;
            pq.push(first + second);
            
        }
        
        return cost;
        // Your code here
    }
};
