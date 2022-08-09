#include<bits/stdc++.h> 
using namespace std; 


int helper(int idx, vector<int> &num, int tar, vector<vector<int>> &dp)
    {
        if(tar == 0) return 1; //arr ke elements hi nah lo
        
        if(idx == 0)
        {
            return (num[0] == tar); //return true if and only if element at arr[0] is 
            //equal to target because there is only 1 element in array now
        }
        
        if(dp[idx][tar] != -1) //if already evaluated
        {
            return dp[idx][tar]; //will return either true or false
        }
        
        int not_take = helper(idx - 1, num, tar, dp);
        int take = 0; //initially
        if(num[idx] <= tar)
        {
            take = helper(idx - 1, num, tar - num[idx], dp);
        }
        
        return dp[idx][tar] = take + not_take;
        
    }



int findWays(vector<int> &num, int tar)
{
     int n = num.size();
     vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
     return helper(n - 1, num, tar, dp); 
       // Write your code here.
}