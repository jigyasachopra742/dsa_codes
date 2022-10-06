#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if(i == j)
    {
        return 0; //koi partition hi nahi ho paayega both the indexes are pointing at the same pos
    }
    
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    
    int mini = 1e9; 
    int steps;
    for(int k = i; k < j; k++) //k is for partition
    {
        steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
        //cumlative  + first + second
        //A*B C*D
        
        mini = min(mini, steps); //returning mini step at each iteration
    }
    
    return dp[i][j] = mini;
    
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1)); 
    return f(1, N - 1, arr, dp); //i = 1, j = N - 1
    //i = 1 because when we multiply the resultant matrices then we take the arr[i - 1] * arr[k] * arr[j] 
    // Write your code here.
}