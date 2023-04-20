#include <bits/stdc++.h> 
using namespace std;

int helper(string &s, string &s2, int idx1, int idx2, vector<vector<int>> &dp)
{
    if(idx1 < 0 || idx2 < 0)
    {
        return 0;
    }
    
    if(dp[idx1][idx2] != -1)
    {
        return dp[idx1][idx2];
    }
    
    //match and non-match
    if(s[idx1] == s2[idx2]) //last index of both is passed in idx1 and idx2
    {
        return dp[idx1][idx2] = 1 + helper(s, s2, idx1 - 1, idx2 - 1, dp); //both the indexs reduce by one
    }
    
    else
    {
        return dp[idx1][idx2] = max(helper(s, s2, idx1 - 1, idx2, dp), helper(s, s2, idx1, idx2 - 1, dp));
    }
    
}
int minCharsforPalindrome(string str) //min number matlab larger length of palindrome
{
    int n = str.size();
    string str2 = str;
    reverse(str2.begin(), str2.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    
    int ans =  helper(str, str2, n - 1, n-1, dp);
    
    int insertions = n - ans; //string length - lps length
    return insertions;
    // Write your code here
}