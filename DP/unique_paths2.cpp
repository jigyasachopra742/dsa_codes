#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    
    int helper(int sr, int sc, int dr, int dc, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid) {
        if(sr >= dr || sc >= dc ) //there is a obstacle in grid
            return 0; //do not count if it's going out of boundary or there is 1(obstacle)int grid
        
        if(sr == dr - 1 && sc == dc - 1) //that means reached the destination
            return 1; //there is a path count it 
        
        if(obstacleGrid[sr][sc] == 1)
            return 0;
        
        if(dp[sr][sc] != -1)
            return dp[sr][sc];
        
        int row = helper(sr + 1, sc , dr, dc, dp, obstacleGrid);
        int col = helper(sr, sc + 1, dr, dc, dp, obstacleGrid);
        
        return dp[sr][sc] = row + col;
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); //row
        int n = obstacleGrid[0].size(); //column
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1 )
            return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, -1)); //initialize 2D dp with -1;
        return helper(0, 0, m, n, dp, obstacleGrid);   //start from top left(0,,0) corner go to bottom right corner (m - 1 , n - 1)
    }
};