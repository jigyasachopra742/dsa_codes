#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //yaha pe yeh approach hai ki pair banalo 
    //closest ele ke liye arr ke ele mai se x minus kardo and unke diff ke basis pe min heap banalo and k jab tak 0 nahi ho jaata tab tak min closest ele to x nikal lo
    //top pe vahi ele honge min
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; //min heap
        //pq.first : abs(arr[idx] - x) 
        //pq.second : arr[idx]
        
        for(int idx = 0; idx < arr.size(); idx++)
        {
           int diff = abs(arr[idx] - x);
           pq.push({diff, arr[idx]}); //sorting on the basis of abs(arr[idx] - k)
        }
        
        vector<int> array;
        while(k--)
        {
            array.push_back(pq.top().second); //the element closest
            pq.pop(); //then pop it
        }
        
        sort(array.begin(), array.end()); //sort it 
        return array;
    }
}; 