#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
      //2sum optimized approach
        unordered_map<int, int> mp;
        vector<int> arr;
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            mp[nums[idx]]++; //frequency map
        }
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            int key = nums[idx]; //number
            int val = mp[nums[idx]]; //freq of that number
            
            int key2 = target - key; //num2 = 9 - 2 = 7
           
            if(key2 == key) //agar simialr key aa gayi tou voh kahi vohi vali tou nahi
            {
                if(val > 1) //if it's freq is greater than 1 matlab voh element 1 se zzayada baar present hai matlab usko ham as a 2nd key consider kar sakte hai
                {
                    arr.push_back(idx);
                }
            }
            
            else //key ke barabar nahi hai
            {
                if(mp.find(key2) != mp.end()) //agar key2 hamko map mai mil jaati hai
                {
                    arr.push_back(idx); //then push it's index
                }
            }
        }
        
        
        return arr;
    }
};