#include <bits/stdc++.h>
using namespace std;

//main thing is we have to move from nth stair to 0th stair either by taking 1 or 2 steps
//and when we reach the 0th staircase we have hit the base case, vaha se return kar jao

class Solution {
public:
    
    //TRY TO REPRESENT PROBLEM IN TERMS OF INDEX
    //FIND THE NUMBER OF WAYS ALL THE WAYS
    //we can either jump 1 or jump 2
    //jab bhi count ways bola always ++++++++++
    //kind of fibonacci
    
    int helper(int n, int t[])
    {
        if(n < 3)  //if number of stairs is less than 3 that is 2 and 1 then we can have only n ways   
        {
            //if 0th stair then only 1 step
            
            return n;
        }
        
        if(t[n] != -1) //storing the steps in array
        {
            return t[n]; //will return the number of ways
        }
        
        else
        {
            return t[n] = helper(n - 1, t) + helper(n - 2, t); //top to down chalre
        }
        
      
    }
    
    int climbStairs(int n) 
    {
        //Each time you can either climb 1 or 2 steps. 
        int t[n + 1];
        memset(t, -1, sizeof(t));
        return helper(n, t);
    }
};