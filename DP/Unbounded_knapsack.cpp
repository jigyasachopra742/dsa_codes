//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        int t[n+1][W+1];
       //BOTTOM-UP APPROACH //TABULATION
       for(int i = 0; i < n + 1; i++) //initialization base condition vali approach
       {
           for(int j = 0; j < W + 1; j++)
           {
               if(i == 0 || j == 0)//either on 0th row or on 0th column
               {
                   t[i][j] = 0;
               }
           }
       }
       
       for(int i = 1; i < n + 1; i++)
       {
           for(int j = 1; j < W + 1; j++)
           {
               if(wt[i-1] <= j) //i is dependent on n, j is dependent on W
               {
                   t[i][j] = max(val[i - 1]+t[i][j-wt[i-1]], t[i-1][j]);
               }
               
               //bas yahape t[i-1][j -wt[i - 1]] => t[i][j- wt[i - 1]]
               //kyunki agar last element dal raha hai tou usko vapis se include kar sakte 
               //voh abhi process nahi hua hai
               //Agar last element fit nahi baithta tou usko include further nahi karenge
               //voh process nahi hua hai
               else
               {
                   t[i][j] = t[i-1][j]; 
               }
           }
       }
       
       return t[n][W];
       
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends