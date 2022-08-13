#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    
    //subsequence : take , not take
    //if do not take that ele, prev index remains the same as we have no taken it 
    
    int helper(int index, int prev_index, vector<int>& nums, vector<vector<int>> &dp, int n)
    {
        int len;
        if(index == nums.size()) //running out of indexes
        {
            return 0;
        }
        //base case //running out of index
        
        if(dp[index][prev_index  + 1] != -1)
        {
            return dp[index][prev_index + 1];
        }
        
        //not take
        len = 0 + helper(index + 1, prev_index, nums, dp, n);

        //take
        if(prev_index == -1 || nums[index] > nums[prev_index])
        {
            len = max(len, 1 + helper(index + 1, index, nums, dp, n));
           
        }
    
        
        return dp[index][prev_index +1] = len; //max length is stored 
    }
    
    int lengthOfLIS(vector<int>& nums) {
        //should be increasing
        //keep track of prev
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1,-1));
        
        return helper(0, -1, nums, dp, n); //current index, prev index
    }
};