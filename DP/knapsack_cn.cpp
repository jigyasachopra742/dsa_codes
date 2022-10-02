#include <bits/stdc++.h> 
using namespace std;

int helper(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int>> &dp)
{
    //last item ke weight se start kar rahe hai and 0th item tak jaa rahe hai
    if(n == 0 || maxWeight == 0) //either the items are 0 or the W is 0
    {
        return 0;
    }
    //here if we are picking up the item with some weight and value then we add it that item into the knapsack and subtract the weight of the item with maxWeight of knapsack and then add the value with it of the item becuase we have to find the max_value and then add the items of weight wi according to the remaining weight of knapsack
    if(dp[n][maxWeight] != -1)
    {
        return dp[n][maxWeight];
    }
    
    if(weight[n - 1] <= maxWeight) //if weight of the last time is <= weight of knapsack then only we can include it in the kanpsack
    {
        return dp[n][maxWeight] = max(value[n - 1] + helper(weight, value, n - 1, maxWeight - weight[n - 1], dp), helper(weight, value, n - 1, maxWeight, dp)); //each time decreasing the index(n - 1) and reaching the 0th item
    }
    
    else{
        return dp[n][maxWeight] = helper(weight, value, n - 1, maxWeight, dp); //here we are not picking up the item hence we will not add it's value and will not substract it from maxWeight and decrase the index as well 
    }
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));
    return helper(weight, value, n, maxWeight, dp);
    // Write your code here
}