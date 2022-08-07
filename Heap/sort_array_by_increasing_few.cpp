#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    class Compare {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b) //pq ka pair hai 
            //uske first mai freq hai second mai ele hai
        {
            if(a.first == b.first) //agar freq similar hai 
                return a.second < b.second; //jo ele greater hoga voh aayega
            return a.first > b.first; //else return the ele which has the greater freq
        }
/*it should have been a.second < b.second and a.first > b.first because we want to
arrange them in ascending order according to second element if first element 
(frequency) is same, but since this is ultimately creating min heap but we need 
max heap so i reversed the greater/lesser signs to make it a max heap*/
};

    
    vector<int> frequencySort(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        vector<int> array;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; //min heap
        for(int idx = 0; idx < nums.size(); idx++)
        {
            mp[nums[idx]]++; //store the freq //freq map
        }
        
        for(auto itr : mp)
        {
            pq.push({itr.second, itr.first}); //pq.push(freq, ele of that freq)
        }
        
        //map mai first parameter is always ele
        //map mai second ele is always feq of that ele
        
        while(pq.size() > 0)
        {
            int freq = pq.top().first;
            int ele = pq.top().second;
            
            for(int idx = 1; idx <= freq; idx++)
            {
                array.push_back(ele);
               
            }
            pq.pop();   
        }
        
        
        
        return array;
    }
};