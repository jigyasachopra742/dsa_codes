#include <bits/stdc++.h>
using namespace std;

//1D DP
//DP SIRF UNHI VARIABLES KI BANTI HAI JO CHANGE HO RAHE HOTE HAI
//AGAR 1 VARIABLE CHANGE, TOU FIR 1D DP
//AGAR 2 THEN 2D DP
//AGAR 3 THEN 3D DP

//t(c) : k times loop chalra k steps for every junction (O(N) * K)
//s(c) : O(N) + O(N) //recursion stack + memorization

//tabulation mai s(c) : O(N) jo jaayegi kyunki recursion stack nahi banra, recursive calls nahi kar rahe

//DP IS OPTIMIZED RECURSION!!!!!
    //JUST KNOW HOW TO MAKE THE CALLS AND COUNT ALL WAYS POSSIBLE
    //MAKE DP OF ONLY THOSE VARIABLES WHICH ARE CHANGING SUPPOSE IN THIS QUESTION 
    //INDEX IS CHANGING WHICH IS STARTING FROM N - 1 AND GOING TILL 0
    //SO WE MADE 1D DP => int dp[n + 1]
    //dp ki dimensions number of states pe depend karti hu
    //jitni states change hogi utni ki DP banti hai
    //agar 3 states change hongi, tou 3D DP banegi
 
int frog(int index, vector<int> &heights, vector<int> &dp, int k)
{
    if(index == 0) //0TH STAIRCASE
    //HIGHEST STAIRCASE SE CHALRE HAM 0 TAK AA RAHE FIR VAHA SE RETURN(VAPIS) JAA RAHE 
    //AND CALCULATE KARTE JAA RAHE

    
    {
        return 0;
    }

    int jumps;
    
    if(dp[index] != -1)
    {
        return dp[index];
    }

    int min_steps = INT_MAX;
    for(int j = 1; j <= k; j++)
    {
        if(index - j >= 0)
        {
            //summation of all the ways(DP RULE)
            jumps = frog(index - j, heights, dp, k) + abs(heights[index] - heights[index - j]);
            min_steps = min(min_steps, jumps); //FIND MINIMUM OF ALL(DP RULE)
        }
    }

    return dp[index] = min_steps;

}


int func(int n, vector<int> &heights)
{
    //START FROM TOP GO TOWARDS BOTTOM IN A TREE. AFTER HITTING BASE CASE RETURN FROM IT 
    //AND THEN KEEP ON STORING THE VALUES THROUGH MEMORIZATION
    int k;
    vector<int> dp(n + 1, -1); 
    return frog(n - 1, heights, dp, k);
}