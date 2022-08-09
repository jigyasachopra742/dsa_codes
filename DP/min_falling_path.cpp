#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //yaha pe fixed ending and fixed strating point nahi hai
    //end row and 0th col of end row
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp)
    {
        //base case
        
        if(i < 0  || j < 0 || j >= matrix[0].size())
        {
            return 1e8; //SO THAT THIS VALUE IS NEVER TAKEN AS IT IS MAXIMUM AND WE WANT THE MINIMUM PATH HERE
        }
        
        if(i == 0) //0th row
        {
            return matrix[0][j]; //return the value at any col because it has reached the boundary of matrix
        }
        
        //2d dp as row and col 2 parameters are changing
        if(dp[i][j] != -1)
        {
            return dp[i][j]; //if the value is already computed store it in dp array
        }
        
        //calculate the max number of ways possible
        
        int upper = matrix[i][j] + helper(i - 1, j, matrix, dp); //upper row same column
        int left_d = matrix[i][j] + helper(i - 1, j - 1, matrix, dp); 
        int right_d = matrix[i][j] + helper(i - 1, j + 1, matrix, dp);
        
        return dp[i][j] = min(upper, min(left_d, right_d)); //abhi tak ek hi col pe work hua 
        //return karte waqt main function pe jaayega vaha se min path lega for 2nd col
    }
    
    //every time ques states there are variable starting points and variable ending points
    //try to explore all the starting points or all the ending points
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        //t(c): O(N x M)
        //S(C) : O(N X M) + O(N) //matrix  + recursion stack => memorization(top down)
        vector<vector<int>> dp(row, vector<int>(col,  -1));

        int mini = 1e8;
        for(int j = 0; j < col; j++) //for different cols on a specfic row
        {
            mini = min(mini, helper(row - 1, j, matrix, dp)); //last row //starting column
        }
        
        return mini;
    }
}; 