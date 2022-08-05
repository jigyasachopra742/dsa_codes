#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //t(c) : O(N);
    //s(c) : O(N) + O(N); //RECURSION + MEMO
    //steps of solving ques using DP
    //step1 : start with index
    //step2: do all the stuffs with the index(count all possible ways and do summation)
    //step3: find the best of them(max or min)
    int solve(vector<int>& nums, vector<int> &dp, int index)
    {
        //n - 1 se chalo go towards  0    
        if(index == 0) //if we are at index = 0  means we have not picked element at index 1 that means we can pick the adjacent ele of 1 makes sense 
            //acc to ques we don't have to pick adjacent elements
            //if we would have picked ele at index 1 then we would have gone to index = -1
            //if not then pick ele at index 0
            //pick : (index - 2) //not picking adjacent ele
            //not pick: (index - 1) //agar pick hi nahi kara tou adjacent vala rule follow hoga hi nahi
        {
            return nums[index]; //return value of nums at index 0
        }
        
        if(index < 0)
        {
            return 0;
        }
        
        if(dp[index] != -1) //agar us index pe value already evaluated hai tou vapis se recursion stack nahi baanyenge
        {
            return dp[index]; //memorization
        }
        
        //subsequence logic(pick and not pick ele)
        
        
        int pick = nums[index] + solve(nums, dp, index - 2);
        int not_pick = 0 + solve(nums, dp, index - 1); //we can pick adjacent vala ele
        
        int max_amt = max(pick, not_pick); //ya fir us ele ko pick karne pe max aayega ya fir usko not pick karne par (this is subsequence)
        return dp[index] = max_amt; //storing max_amt in dp array
    }
    
    int rob(vector<int>& nums) //array nums representing the amount of money of each house
    {
        int n = nums.size();
        //maximum sum of non-adjacent elements
        vector<int> dp(n + 1, -1); //initialized dp with -1;
        //since only 1 variable index will be changing here, so dp will be of 1 dimension
        //that is 1D DP => dp[n + 1]
        
        return solve(nums, dp, n - 1); //start from last index
    }
};