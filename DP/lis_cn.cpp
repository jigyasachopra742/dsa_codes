#include <bits/stdc++.h> 
using namespace std;

int helper(int idx, int prev_idx, vector<int> &heights, int n,  vector<vector<int>> &dp)
{
      if(idx == heights.size()) //all the ele are used
      {
          return 0;
      }
      
      if(dp[idx][prev_idx + 1] != -1)
      {
          return dp[idx][prev_idx + 1];
      }
    
      int len = 0 + helper(idx + 1, prev_idx, heights, n, dp); //update the existing len
      //not taking that ele in subsequence going to next index , prev_idx remains the same as we are not taking the current ele into account

      if(prev_idx == -1 || heights[idx] > heights[prev_idx]) //increasing
      {
          len = max(len, 1 + helper(idx + 1, idx, heights, n, dp)); //taking that ele in subsequence
      }

      return dp[idx][prev_idx + 1] = len; 
}


int LIS(vector<int> &heights, int n){
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(0, -1, heights, n, dp); //strat from 0 index and prev_index = -1
    // Write your code here.
    
}
