class Solution {
public:
/* You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.*/

    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        int t[n + 1][amount + 1]; //we have to find that sum
        
        for(int j = 0; j < amount + 1; j++)
        {
            t[0][j] = 0;  //false
        }
        
        for(int i = 0; i < n + 1; i++)
        {
            t[i][0] = 1; //true
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 0; j < amount + 1; j++)
            {
                if(coins[i - 1] <= j)
                {
                    t[i][j] = (t[i][j - coins[i-1]] + t[i-1][j]); //include + exclude
                }
                
                else
                {
                    t[i][j] = (t[i-1][j]); //exclusing if greater
                }
            }
        }
        
        return t[n][amount];
    }
};