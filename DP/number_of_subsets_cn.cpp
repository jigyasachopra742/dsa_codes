#include <bits/stdc++.h> 
using namespace std;

int helper(int idx, vector<int> &num, int sum, vector<vector<int>> &dp)
    {
        if(sum == 0) return 1; //arr ke elements hi nah lo
        
        if(idx == 0)
        {
            return (num[0] == sum); //return true if and only if element at arr[0] is 
            //equal to target because there is only 1 element in array now
        }
        
        if(dp[idx][sum] != -1) //if already evaluated
        {
            return dp[idx][sum]; //will return either true or false
        }
        
        int not_take = helper(idx - 1, num, sum, dp);
        int take = 0; //initially
        if(num[idx] <= sum)
        {
            take = helper(idx - 1, num, sum - num[idx], dp);
        }
        
        return dp[idx][sum] = not_take + take;
        
    }



int findWays(vector<int> &num, int tar)
{
     int n = num.size();
     vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
     return helper(n - 1, num, tar, dp); 
       // Write your code here.
}