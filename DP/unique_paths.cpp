#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //T(C) : O(M*N) //2 CALLS IN M ROWS N COLS
    //FOR EVERY BOX WE ARE TAKING 2 PATHS EITHER THROUGH ROW OR THROUGH COL
    //S(C) : O(PATH LENGTH)
    
    int helper(int sr, int sc, int dr, int dc , vector<vector<int>> &dp)
    {
        if(sr == dr - 1 && sc == dc - 1) 
        {
            return 1; //reached destination on returning 1 it gets counted
        }
        
        if(sr >= dr || sc >= dc) //boundary //exceeding the boundary rowwise or columnwise
        {
            return 0; //not a path because it took us out of the boundary
            //do not count this path
        }
        
        if(dp[sr][sc] != -1)
        {
            return dp[sr][sc]; //if it is already evaluated, return it
        }
        
        //explore all ways possible
        int row, col;
       
        row = helper(sr + 1, sc, dr, dc, dp); //down calculate while making recursive calls
        
        col = helper(sr, sc + 1, dr, dc, dp); //right calculate while making recursive calls
        

        return dp[sr][sc] = row + col;
    }
    
    //so here 2 parametrs are changing so we will make 2d dp
    //m and n
    //take everything in terns of indexes
    //sum up all ways
    //then find max or minimal
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1)); //initialize 2D dp with -1;
        return helper(0, 0,m, n, dp);  
    }
};