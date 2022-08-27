#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit1 = 0;
        int mini1 = INT_MAX;
        int profit2 = 0;
        int mini2 = INT_MAX;
        
        for(int idx = 0; idx < prices.size(); idx++)
        {
            mini1 = min(mini1, prices[idx]);
            profit1 = max(profit1, prices[idx] - mini1);
            mini2 = min(mini2, prices[idx] - profit1); //hame already ek profit ho chuka hai tou next stock buy karte waqt ham current price  mai se minus karke us price pe us stock ko buy kar sakte hai
            profit2 = max(profit2, prices[idx] - mini2);
        }
        
        return profit2;
    }
}; 