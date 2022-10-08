#include <bits/stdc++.h> 
using namespace std;

int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if(i > j)
    {
        return 0;
    }
    
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    
    int mini = INT_MAX;
    for(int idx = i; idx <= j; idx++)
    {
        int steps = cuts[j + 1] - cuts[i - 1] + helper(i, idx - 1, cuts, dp) + helper(idx + 1, j, cuts, dp);
        
        mini = min(mini, steps);
    }
    
    return dp[i][j] = mini;
}

int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n); //push the length at the end
    cuts.insert(cuts.begin (), 0); //insert 0 at the beginning
    sort(cuts.begin(), cuts.end()); //sort the array tabhi independently solve kar paayenge
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return helper(1, c, cuts,dp);
    // Write your code here.
}