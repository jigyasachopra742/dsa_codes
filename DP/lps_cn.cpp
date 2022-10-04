#include <bits/stdc++.h> 
using namespace std;

//the portion of string which is present in both s and s2 we call it as lcs
int helper(string &s, string &s2, int idx1, int idx2, vector<vector<int>> &dp) //idx1 = n - 1 , idx2 = n-1
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


int longestPalindromeSubsequence(string s)
{
    int n = s.size();
    string s2 = s;
    reverse(s2.begin(), s2.end());
    //common string between s and s2 //find lcs between them 
    //if the reverse of lcs is also the same then it is a palindrome
    //lcs(s, s2);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(s, s2, n - 1, n - 1, dp); //2 last indexes of both the strings
    // Write your code here.
}