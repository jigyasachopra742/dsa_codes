#include<bits/stdc++.h>
using namespace std;

class Solution 
{

    //here we have to return the k numbers which have largest fequencies
    //for frequencies we use hashmap
    
    // [1,1,1,2,2,3], k = 2
    //[1,2] => 1 has freq 2, 2 has freq 2 //top k ele
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> ourmap;     //make a freq map

        vector<int> array;
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            ourmap[nums[idx]]++; //storing freq
        }
        
        priority_queue<pair<int,int>> pq; //max heap mai pair
        for(auto itr : ourmap)
        {
           pq.push({itr.second, itr.first}); //1st mai freq //2nd mai ele of that freq
        }
        
        while(k--)
        {
            array.push_back(pq.top().second); //top element is pushed in array
            pq.pop();  //then pop it
        }
        
        return array;
    }
};