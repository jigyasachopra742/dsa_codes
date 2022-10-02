#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    int helper(int idx, vector<int>& coins , int amount, vector<vector<int>> &dp)
    {
        
        if(idx == 0)
        {
            if(amount % coins[idx] == 0)
            {
                return 1; //as the ques has asked number of ways
            }
            
            else
            {
                return 0;
            }
        }
        
        
        if(dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }
        
        
        int not_take = helper(idx - 1, coins, amount, dp);
        int take = 0;
        
        if(coins[idx] <= amount)
        {
            take = helper(idx, coins, amount - coins[idx],dp); //do not move back to prev index
        }
        
        return dp[idx][amount] = take + not_take;
    }
    
    
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        
        int ans = helper(n - 1, coins, amount, dp);
        if(ans >= INT_MAX)
        {
            return 0;
        }
        
        return ans;
    }
};