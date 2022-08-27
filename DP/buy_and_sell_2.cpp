#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //before buying the stock you should have sell previous buying stock
        //maximize the profit
        
        //keep track of previous
        int profit = 0;
        for(int idx = 1; idx < prices.size(); idx++) //[1,2,3,4,5]
        {
            if(prices[idx] > prices[idx - 1]) //prices[4] > prices[3] = 5 > 4
            {
                profit+= (prices[idx] - prices[idx - 1]); 
                //profit = 3 + 5 - 4 = 4
            }
        }
        
        return profit; //4
    }
    
};
