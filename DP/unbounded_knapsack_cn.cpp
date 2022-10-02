#include <bits/stdc++.h> 
using namespace std;

int helper(int idx, int w,  vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if(idx == 0) //if at this index there is some value then we can defintely steal it to gain max profit , jitna gain kar sakte ho karo
    {
        int total = (w / weight[0]) * profit[0]; 
        return total;
    }
    
    if(dp[idx][w] != -1)
    {
        return dp[idx][w];
    }
    
    int not_take = helper(idx - 1, w, profit, weight, dp);
    int take = INT_MIN;
    
    if(weight[idx] <= w)
    {
        //unbounded knapsack , remain on the same index
        take = profit[idx] + helper(idx, w - weight[idx], profit, weight, dp);
    }
    
    return dp[idx][w] = max(take, not_take);
}
    
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    return helper(n - 1, w, profit, weight, dp); //last index
    // Write Your Code Here.
}
