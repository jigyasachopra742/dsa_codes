class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        int t[n + 1][amount + 1]; 
        
        for(int i = 0; i < n + 1; i++)
        {
            t[i][0] = 0; //amount agar 0 hai tou return min amt 0 //this array returns amt
        }
        //sum/value of the coin = no. of coins used to achieve that particular sum, So whenever no. of coins is 0, implies value also 0, which is in denominator, So no. of coins used is infinity(INT_MAX).
        for(int j = 0; j < amount + 1; j++)
        {
            t[0][j] = INT_MAX - 1; //agar number of coins nahi hai tou infinite ho sakte
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < amount + 1; j++)
            {
                if(coins[i - 1] <= j)
                {
                    t[i][j] = min(t[i][j-coins[i-1]] + 1, t[i-1][j]);
                }
                //+1 is for including coins . 1 coin add karlia tou ++ karlo
                else
                {
                    t[i][j] = t[i-1][j]; //excluding
                }
            }
        }
        
        return t[n][amount] == INT_MAX-1 ? -1 : t[n][amount];
    }
};