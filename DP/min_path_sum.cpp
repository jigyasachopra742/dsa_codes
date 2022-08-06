#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int helper(int sr, int sc, int dr, int dc, vector<vector<int>> &dp, vector<vector<int>>& grid)
    {
        if(sr == dr - 1 && sc == dc - 1) //destination reached
        {
            return grid[sr][sc]; //consider it as a path
        }
        
        if(sr >= dr || sc >= dc) //out of boundary
        {
            return INT_MAX; //not a path out of boundary
        }
        
        if(dp[sr][sc] != - 1)
        {
            return dp[sr][sc]; //if it is already calculated then do not make recursion stack again don't make recursive calls again
        }
        
        //always make a tree of left call and right call
      
        //trying out all paths //make all the calls
        int row = helper(sr + 1, sc, dr, dc, dp, grid); //down
        int col = helper(sr, sc + 1, dr, dc, dp, grid); //right
        //now tell the path which has min cost
        //ya fir tou rowwise min path aayega ya fir column wise and jo bhi min aata hai usmei cost ko add kardo
        return dp[sr][sc] =  grid[sr][sc] +  min(row, col); //cost ko add karte jao in min path
      
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(); //row
        int n = grid[0].size(); //col
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(0, 0, m, n, dp, grid); //start from(0, 0) go to (n - 1, m - 1)
        
        
    }
}; 