#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        unordered_map<int , int>ourmap; //1st is for num , 2nd is for frequency
        vector<int>array;
        for(int idx = 0 ; idx < nums.size() ; idx++)
        {
            ourmap[nums[idx]]++; //this statement means that while adding elements there frequency is also added
        }
        
        sort(begin(nums),end(nums),[&](int a,int b) //comparator //operator , custom comparison ke liye (badha , chota dekhega)
             {
                return ourmap[a] == ourmap[b] ? a > b : ourmap[a] < ourmap[b];
             }
        );
        //agar frequencies of 1st 2 values is same then return the gratr number (decraesing order) if not then return in increasing order
        return nums;
    }
};