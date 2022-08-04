#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //DP UNHI KI BANTI HAI JO VARIABLES CHANGE HOTE REHTE HAI
    //TC: O(n)
    //SC : O(N) (STACK) + O(N) (ARRAY)
    int func(int n, vector<int> &dp) //TOP DOWN DP //n = 5
    {
        if(n <= 1) return n; //base condition
        
        if(dp[n] != -1) //if that value has already been computed, it is stored in dp[n] array
        {
            return dp[n];
        }
        
        //in memorization we have recursive calls and a table of variables which are changing
        
        return dp[n] = func(n - 1, dp) + func(n - 2, dp); //if not computed then store the values in dp[n] array
    }
    
    int fib(int n) 
    {
        vector<int> dp(n + 1, -1); //store -1 in dp array initially
        //jaise hi compute hote jaaye store them in an array dp[n] 
        return func(n, dp);
    }
};