#include <bits/stdc++.h> 
using namespace std;

int helper(vector<int> &price, int idx,  int n, vector<vector<int>> &dp)
{
    
    if(idx == 0)
    {
        return n * price[0]; //jitna padha hua hai utna hi lelo to gain max profit
        
    }
    if(dp[idx][n] != -1)
    {
        return dp[idx][n];
    }
    
    int not_take = helper(price, idx - 1, n,  dp);
    int take = INT_MIN;
    
    int rod_len = idx + 1; //becuase rod ka array nahi diya hua hai
    //and indexing 0 se start ho rahi so rod_len will be idx + 1
    if(rod_len <= n)
    {
        take = price[idx] + helper(price, idx, n - rod_len, dp); //total_len mai se jo rod ki len cut kari hai voh minus kardo
    }
    
    return dp[idx][n] = max(take, not_take); 
    //index and rod ki length is changing so usi ki dp array banegi
    //jo variables change ho rahe hote hai unhi ki dp banti hai
}


int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(price, n - 1, n, dp);
    // Write your code here.
}
