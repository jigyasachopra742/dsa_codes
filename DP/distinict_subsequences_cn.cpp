#include <bits/stdc++.h> 
using namespace std;

int helper(int idx1, int idx2, string S, string T, vector<vector<int>> &dp) 
{
    if(idx2 < 0)
    {
        return 1; //that means all the characters of T are matched in S
    }
    
    if(idx1 < 0)
    {
        return 0; //that means the string S is exhausted and there are some characters in string T remaining    
    }
    
    if(dp[idx1][idx2] != -1)
    {
        return dp[idx1][idx2];
    }
    
    if(S[idx1] == T[idx2]) //last index is passed
    {
        return dp[idx1][idx2] = helper(idx1 - 1, idx2 - 1, S, T, dp) + helper(idx1 - 1, idx2, S, T, dp); //f(i - 1, j - 1) + f(i - 1, j)
        //by chance agar hamei last match karna ka mann nahi hai , hamei last char of j ko pichle last ke 2nd char se match karne ka mann hai 
    }
    
    return dp[idx1][idx2] = helper(idx1 - 1, idx2, S, T, dp); //if the last char of both the strings don't match then reduce the range of string 1 
}


int numDistinct(string S, string T) 
{
    int n = S.size();
    int m = T.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
    return helper(n - 1, m - 1, S, T, dp);
    // Write your code here
}