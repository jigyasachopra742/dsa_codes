#include <bits/stdc++.h> 
using namespace std;

int helper(int idx, vector<int> &arr, int target, vector<vector<int>> &dp)
    {
     
        if(idx == 0)
        {
           if(target == 0 && arr[0] == 0) return 2;
           if(target == 0 || target == arr[0]) return 1;
            
           return 0;
        }
        
        if(dp[idx][target] != -1) //if already evaluated
        {
            return dp[idx][target]; //will return either true or false
        }
        
        int not_take = helper(idx - 1, arr, target, dp);
        int take = 0; //initially
        if(arr[idx] <= target)
        {
            take = helper(idx - 1, arr, target - arr[idx], dp);
        }
        
        return dp[idx][target] = (not_take + take);
        
    }


int findWays(vector<int> &arr, int target)
{
     int n = arr.size();
     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
     return helper(n - 1, arr, target, dp); 
       // Write your code here.
}

int count_partitions(int n, int target, vector<int> &arr) 
{
    //count partitions with given difference 
    int tot_sum = 0;
    //tot_sum = s1 + s2;
    //s1 - s2 = d (s1 > s2)
    //tot_sum - s2 - s2 = d
    //tot_sum - 2*s2 = d
    //s2 = tot_sum - d/2
    for(int idx = 0; idx < n; idx++)
    {
        tot_sum+= arr[idx];
    }
    
    if(tot_sum - target < 0 || (tot_sum - target) % 2 != 0)
    {
        return false;
    }
    
    //it is ACTUALLY COUNT SUBSETS WITH A GIVEN TARGET
    return findWays(arr, (tot_sum - target)/2);
    // Write your code here.
}

int targetSum(int n, int target, vector<int>& arr) 
{
    return count_partitions(n, target, arr);
    // Write your code here.
}
