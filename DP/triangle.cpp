#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    
    //BAS DIAGONALLY CHALNA HAI SIMILAR TO MIN PATH SUM 
    
    int helper(int sr, int sc, int dr, int dc, vector<vector<int>> &dp, vector<vector<int>>& triangle)
    {
         if(sc == triangle[sr].size()) //yeh nahi lagaya tha isiliye runtime aaya tha 
             //column overflow hai yeh
            return 10001;
        if(sr == dr - 1) //if it reaches the last row the destination
        {
            return triangle[dr - 1][sc];
        }
        
        if(dp[sr][sc] != -1)
        {
            return dp[sr][sc];
        }
        
        int down = triangle[sr][sc] + helper(sr + 1, sc, dr, dc, dp, triangle); //TAKE THAT VARIABLE AND MAKE A RECURSIVE CALL FOR NEXT ELEMENT
        int diag = triangle[sr][sc] + helper(sr + 1, sc + 1, dr, dc, dp, triangle);
        
        return dp[sr][sc] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size(); //row
        //kitne bhi cols ho sakte hai
        //cols row ke hisab se ban rahe
        
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return helper(0, 0, m, m, dp, triangle);
    }
};