#include<bits/stdc++.h>
using namespace std;

//ONLY RECURSIVE CALLS
//GIVES TLE
//BUT FIRST DO THIS BEFORE OPTIMAL APPROACH

 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        //USING RECURSION
       if(n == 0 || W == 0) //base condition
       {
           return 0;
       }
       
       if(wt[n - 1] <= W)
       {
           return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n-1), knapSack(W , wt, val, n-1));
       }
       
       if(wt[n - 1] > W)
       {
           return knapSack(W , wt, val, n-1);
       }
       
       
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