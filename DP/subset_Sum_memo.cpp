#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:

    bool helper(int idx, vector<int> &arr, int sum, vector<vector<int>> &dp)
    {
        if(sum == 0) return true; //arr ke elements hi nah lo
        
        if(idx == 0)
        {
            return (arr[0] == sum); //return true if and only if element at arr[0] is 
            //equal to target because there is only 1 element in array now
        }
        
        if(dp[idx][sum] != -1) //if already evaluated
        {
            return dp[idx][sum]; //will return either true or false
        }
        
        bool not_take = helper(idx - 1, arr, sum, dp);
        bool take = false; //initially
        
        if(arr[idx] <= sum)
        {
            take = helper(idx - 1, arr, sum - arr[idx], dp);
        }
        
        return dp[idx][sum] = take || not_take;
        
    }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(n - 1, arr, sum, dp); 
        
        //sum is my target
        // code here 
    }
};