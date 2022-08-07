#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    long long kthsmallest(long long A[], long long N, long long K)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq; //min heap
        for(int idx = 0; idx < N; idx++)
        {
            pq.push(A[idx]); //pushing the array ele in pq
        }
        
        long long ans1;
        while(K--)
        {
            ans1 = pq.top(); //we will get the K1 ele
            pq.pop();
        }
        
        return ans1; //K1 element
    }
    
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        long long first = kthsmallest(A, N, K1);
        long long second = kthsmallest(A, N, K2);
        long long sum = 0;
        
        for(int idx = 0; idx < N; idx++)
        {
            if(A[idx] > first && A[idx] < second)
            {
                sum+= A[idx];
            }
        }
        
        return sum;
        
        // Your code goes here
    }
};