#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    /*
        
    If the absolute value of target is greater than sum then there exists no solutions abs(target) > sum
and one more condition needs to be checked i.e. if ((sum + target)%2 != 0) then we would never get the difference target by partitioning the array into two subsets.
Why are we not initializing entire first col to 1 ? like we did in the previous problem it's because here in this problem, we may get 0 as input. Now when we get 0 as input, we have to consider two choices : include this 0 to form subset with sum 0, or exclude this 0 to form subset with sum 0. We initialize entire first col with 1 when we are sure that in the input we will be given numbers >=1 .
    
    
    
    
    */
    
    int count_subsets(vector<int>& nums, int sum1, int target)
    {
        int n = nums.size();
        int t[n + 1][sum1 + 1]; //we have to find that sum
        
        for(int j = 0; j < sum1 + 1; j++)
        {
            t[0][j] = 0;  //false
        }
        
        for(int i = 0; i < n + 1; i++)
        {
            t[i][0] = 1; //true
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 0; j < sum1 + 1; j++)
            {
                if(nums[i - 1] <= j)
                {
                    t[i][j] = (t[i-1][j - nums[i-1]] + t[i-1][j]); //include + exclude
                }
                
                else
                {
                    t[i][j] = (t[i-1][j]); //exclusing if greater
                }
            }
        }
        
        return t[n][sum1];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        //count  number of subsets with given difference 
        int sum_of_arr = 0;
        int sum1 = 0;
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            sum_of_arr+= nums[idx];
        }
        
         if (abs(target) > sum_of_arr || (sum_of_arr + target) % 2 != 0){ 
            return 0;
        }
        
        sum1 = (target + sum_of_arr)/2;
       
        
        return count_subsets(nums, sum1, target);

    }
};