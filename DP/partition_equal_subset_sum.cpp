#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    //approach: sabse phele tou hamko voh equal subsets find karne hai jinka sum equal hai. Obviously jin elements ka sum even aayega agar even number ko half karenge tou we will get equal numbers, equal partition. Agar sum odd aata hai tou equal partition ho hi nahi sakta, half mai divide ho hi nahi sakta so in that case return false. Agar sum even aa jata hai then do sum = sum /2 suppose sum aaya 22 it can be halved as 11(ek subset ka sum mil gaya ab dusre ka find karenge jo iske equal hoga using subsets sum technique). Now we will 11 for another subset in the array nums.
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        
        for(int idx = 0; idx < n; idx++)
        {
            sum+= nums[idx];
        }
        
        if(sum % 2 != 0) //odd
        {
            return 0;
        }
        
        else if(sum % 2 == 0) //even
        {
            sum = sum /2; //now we will find whether this sum exists in the subset or not
        }
        
        vector<vector<int>>t(n+1, vector<int>(sum+1));
        for(int i = 0; i < n + 1; i++)
        {
            t[i][0] = 1; //return true for sum = 0 , empty subset
        }
        
        for(int j = 0; j < sum + 1; j++)
        {
            t[0][j] = 0; //return false for 0 array elements
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < sum + 1; j++)
            {
                if(nums[i - 1] <= j)
                {
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                                     
               else{
                   
                   t[i][j] = t[i-1][j];
               }                                              
                                     
            }
         }
         return t[n][sum];                             
    }
};