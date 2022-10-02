#include <bits/stdc++.h> 
using namespace std;
int mod = (int) (1e9 + 7);

int helper(int idx, vector<int> &num, int sum, vector<vector<int>> &dp)
    {
     
        if(idx == 0)
        {
           if(sum == 0 && num[0] == 0) return 2;
           if(sum == 0 || sum == num[0]) return 1;
            
           return 0;
        }
        
        if(dp[idx][sum] != -1) //if already evaluated
        {
            return dp[idx][sum]; //will return either true or false
        }
        
        int not_take = helper(idx - 1, num, sum, dp);
        int take = 0; //initially
        if(num[idx] <= sum)
        {
            take = helper(idx - 1, num, sum - num[idx], dp);
        }
        
        return dp[idx][sum] = (not_take + take) % mod;
        
    }



int findWays(vector<int> &num, int tar)
{
     int n = num.size();
     vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
     return helper(n - 1, num, tar, dp); 
       // Write your code here.
}

int countPartitions(int n, int d, vector<int> &arr) 
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
    
    if(tot_sum - d < 0 || (tot_sum - d) % 2 != 0)
    {
        return false;
    }
    
    //it is ACTUALLY COUNT SUBSETS WITH A GIVEN TARGET
    return findWays(arr, (tot_sum - d)/2);
    // Write your code here.
}


