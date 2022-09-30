#include <bits/stdc++.h> 

bool f(int idx, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if(k == 0) return true;
    
    if(idx == 0)
    {
        return (arr[0] == k); //return either true or false
    }
    
    if(dp[idx][k] != -1) //if that is already evaluated then simply return the value
        //overlapping subproblems
    {
        return dp[idx][k]; 
    }
    
    bool not_take = f(idx - 1, k, arr, dp); //do not reduce the target
    bool take = false; 
    if(arr[idx] <= k)
    {
        take = f(idx - 1, k - arr[idx], arr, dp);
    }
    
    return dp[idx][k] = not_take | take; //if either of them returns true , the return it
}
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    //initializing the dp array with -1
    return f(n - 1, k, arr, dp);
    // Write your code here.
}