#include <bits/stdc++.h>
using namespace std;

//fixed starting point 
//variable ending point
class Solution {
public:
    //IF WE RETURN INT MIN IT WILL GET ADDED TO INT IF THAT INT IS NEGATIVE WHICH WILL GO BEYOND //HENCE RUNTIME ERROR (OUT OF BOUND)
    //just take one i (i + 1) for both R1 and R2
    //j is changing simultaneously(j - 1, j, j + 1) (-1, 0 , +1) for R1 and R2
    
    int helper(int i, int j1, int j2, int row, int col, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        if(j1 < 0 || j1 >= col || j2 < 0 || j2 >= col) //out of bounds //left or right boundary
        {
            return -1e8; //return the min value so that it never returns this
        }
        
        //destination vala base case
        if(i == row - 1) //last row
            ///last row pe aake remaining ke liye call kyu hi karoge
        {
            if(j1 == j2) //if R1 nad R2 reach the same point count that as same only
            {
                return grid[i][j1]; //return either of them 
            }
            
            else
            {
                return grid[i][j1] + grid[i][j2]; //return sum of both
            }
        }
        
        if(dp[i][j1][j2] != -1) //already evaluated
        {
            return dp[i][j1][j2];  //return it
        }
        
        //explore all the paths of R1 and R2 simultaneously
        //this is except the last row cases
        int maxi = -1e8;
        for(int d1 = -1; d1 <= 1; d1++) //for R1 3 paths
        {//if R1 can move int j-1 direction, R2 can move in any of the 3 wrt R1 simulataneously
            for(int d2 = -1; d2 <= 1; d2++) //for R2 3 paths
            {
                int val = 0;
                if(j1 == j2) //same path
                {
                    val =  grid[i][j1]; //only 1 of them
                }
                
                else
                {
                    val =  grid[i][j1] + grid[i][j2]; //sum of both R1 and R2
                }
                
                //take the ele and call for remaining ones (RULE OF DP)
                val+= helper(i+1, j1+d1, j2+d2, row, col, grid, dp); //callling for remaining blocks          
                maxi = max(maxi, val); //max of all the paths explored by R1 and R2 together
                
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        
        //int dp[r][c][c]; //here 3 para are changing row of both col of R1 and col of R2
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        
        
        //BASE CASE => DESTINATION + OUT OF BOUND
        // maximum number of cherries collection using both robots
        //all paths by R1 nad R2 together
        //write recursion for R1 and write recursion for R2
        //there can be a common path
        //express everything in terms of i and j
        //R1 => i1, j1, R2=>i2, r2 //R1 =>(0,0), R2=>(0, M - 1)
        //explore all the paths
        //find maximum
        //can end at any column at the last row
        return helper(0, 0, col - 1, row, col, grid, dp);
        //R1 ke liye i = 0 , j = 0 //1st col 1st row (acc to ques)
        //R2 ke liye i = 0, j = col - 1 //last col 1st row
        
    }
};