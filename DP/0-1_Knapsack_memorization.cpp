#include<bits/stdc++.h>
using namespace std;

//FOR MEMORIZATION(TOP DOWN), always store the result in a matrix of size of the variables 
//which are changing in the recursive calls.

//ALways first do recursion(BRUTE FORCE) and then go towards BOTTOM UP(DP) or TOP DOWN(MEMORIZATION)
//in TOP DOWN, we memorize the values so that recursive calls are not made again and again
//and stack size does not fill and saves time
//INITIALIZE MATRIX WITH -1
//agar matrix mai -1 nahi hoga , koi aur value hogi matlab voh already evaluate ho chuka hai uspe aur work nahi karna hai
//recursion + matrix

//Matrix is always of the variables which change in the recursive calls
//FOR DP ALWAYS REMEMBER:
//1. CHOICE DIAGRAM(2 RECURSIVE CALLS CONTINUOUSLY)
//2. OPTIMAL APPROACH(MAX, MIN, SMALLEST, LARGEST)

 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapSack_sol(vector<vector<int>>& t,int W, int wt[], int val[], int n)
    {
        if(n == 0 || W == 0)
        {
            return 0;
        }
        
        if(t[n][W] != -1)
        {
            return t[n][W];
        }
        
        if(wt[n - 1] <= W)
        {
            return t[n][W] = max(val[n - 1] + knapSack_sol(t, W-wt[n-1], wt, val, n-1), knapSack_sol(t, W, wt, val, n-1));
        }
        
        else if(wt[n - 1] > W)
        {
            return t[n][W] = knapSack_sol(t, W, wt, val, n-1);
        }
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>t(n+1, vector<int>(W+1, -1));
       return knapSack_sol(t, W, wt, val, n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends