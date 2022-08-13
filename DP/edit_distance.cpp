#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    
    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        //in insertion, we are adding characters in word1 so that they match in word2
        //so in insertion we are not reducing word1, it remains the same, it's indexes do not move hence here we do not do i - 1, but since we are matching it with j so j will reduce to j - 1 after matching
        
        //in deletion we are deleting some characters from word1 to match to word2, so word1 => i - 1 and word2 remains the same since we are only making changes to word1 to match it to word2
        
        //in replacing we are replacing a character in word1 similar to word2, so after replacing they match and if they match , now we will traverse on the remaining characters in both
        //base case
        if(j < 0)
        {
            return i + 1; //deletion steps to make i equal to j
        }
        
        if(i < 0)
        {
            return j + 1; //insertion steps to make i equal to j
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        //possible ways
        if(word1[i] == word2[j])
        {
            return dp[i][j] = helper(i - 1, j - 1, word1, word2, dp); //no steps to do as they have matched so no insertion, deletion or replacing
        }
        
        else
        {
            return dp[i][j] = 1 + min( helper(i - 1, j, word1, word2, dp), min(helper(i, j - 1, word1, word2, dp), helper(i - 1, j - 1, word1, word2, dp)));
        }
        
    }
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, word1, word2, dp);
    }
}; 