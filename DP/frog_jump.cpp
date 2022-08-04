#include <bits/stdc++.h>
using namespace std;

//1D DP
//DP SIRF UNHI VARIABLES KI BANTI HAI JO CHANGE HO RAHE HOTE HAI
//AGAR 1 VARIABLE CHANGE, TOU FIR 1D DP
//AGAR 2 THEN 2D DP
//AGAR 3 THEN 3D DP

int frog(int index, vector<int> &heights, vector<int> &dp)
{
    if(index == 0)
    {
        return 0;
    }

    if(dp[index] != -1)
    {
        return dp[index];
    }

    int right_call = INT_MAX; //incase of f(1) while returning we did not have right call kyunki f(0) se f(1) vapis se call hua
    int left_call = frog(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]); //either 1 step from current value

    if(index > 1) //kyunki right 2 steps le raha hai 
    //agar 1st step pe khade hai tou 2 steps lega tou voh -1 ho jaayega 
    //agar 1 step lega tou difference 1 hi aayega
    {
        right_call = frog(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]); //either 2 steps from the current value
    }

    return dp[index] = min(left_call, right_call);
}


int func(int n, vector<int> &heights)
{
    //START FROM TOP GO TOWARDS BOTTOM IN A TREE. AFTER HITTING BASE CASE RETURN FROM IT 
    //AND THEN KEEP ON STORING THE VALUES THROUGH MEMORIZATION
    vector<int> dp(n + 1, -1);
    return frog(n - 1, heights, dp);
}