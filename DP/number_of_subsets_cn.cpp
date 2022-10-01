#include <bits/stdc++.h> 
using namespace std;

int helper(int idx, vector<int> &num, int sum, vector<vector<int>> &dp)
    {
     
        if(idx == 0)
        {
           if(sum == 0 && num[0] == 0) return 2;
           if(sum == 0 || sum == num[0]) return 1;
            
           return 0;
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