#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //if you are selling on ith day , you buy on the minimum price from 1st->(i - 1)
    int maxProfit(vector<int>& prices) 
    {
        int mini = prices[0], profit = 0; //if you buy and sell on the same day the profit is 0 //mini = 7
        int cost;
        for(int idx = 1; idx < prices.size(); idx++)
        {
            cost = prices[idx] - mini;  //cost = 1 - 7 = -6
            profit = max(profit, cost); //profit = max(0, -6) = 0
            mini = min(mini, prices[idx]); //mini = min(7, 1) = 1
            //hamko buy kam pe karna hai and sell zzayada pe tabhi profit hoga
        }
        
        return profit;
    }
};//obviously agar ham mini price pe buy karenge and zzyada price pe sell karenge tou profit zzyada hoga