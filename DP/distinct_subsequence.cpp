#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    
    int helper(int i, int j, string& s, string& t, vector<vector<int>> &dp)
    {
        //base case
        if(j < 0) //that means everything in j has been used up (matched in i)
        {
            return 1;
        }
        

        if(i < 0)
        {
            return 0; //matlab ki kuch match hua hi nahi hai i mai j ka and j as it is padha hua hai then there is no subsequence
        }
        
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(s[i] == t[j]) //last char matches of both
        {
             return dp[i][j] = helper(i - 1, j - 1,s,t,dp) + helper(i - 1, j,s,t,dp); //match + don't match
        }
        
    
        return  dp[i][j] = helper(i - 1, j, s, t, dp); //dosen't match(like knapsack)
        
         
        

        //possible ways
    }
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1,s, t, dp); //start matching from last
    }
}; 