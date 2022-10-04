#include <bits/stdc++.h> 
using namespace std;

int helper(int idx1, int idx2, string &str1, string &str2, vector<vector<int>> &dp)
{
    if(idx1 < 0) //that means idx2 + 1 insertions in str1 to make it str2 since str1 in this case is empty(exhausted), it's index is at -1
    {
        return idx2 + 1; //insertions
    }
    
    if(idx2 < 0) //that means idx1 + 1 deletions in order to make str1 into an empty string since str2 is empty becuase it's index is at -1
    {
        return idx1 + 1; //deletions to make str1 empty like str2
    } 
    
    
    if(dp[idx1][idx2] != -1)
    {
        return dp[idx1][idx2];
    }
    
    if(str1[idx1] == str2[idx2]) //last character matches
    {
        return dp[idx1][idx2] = 0 + helper(idx1 - 1, idx2 - 1, str1, str2, dp);
    }
    
    else
    {
        return dp[idx1][idx2] = 1 + min(helper(idx1, idx2 - 1, str1, str2, dp), min(helper(idx1 - 1, idx2, str1, str2, dp), helper(idx1 - 1, idx2 - 1, str1, str2, dp)));
    }
}


int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return helper(n - 1, m - 1, str1, str2, dp);
    //write you code here
}