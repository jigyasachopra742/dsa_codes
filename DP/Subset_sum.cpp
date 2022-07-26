//initialization

//AGAR sum = 0 and array.size() == 0 , TRUE(EXCEPTION)
//Agar sum = 0 and array.size() == 2, TRUE(Empty subsets)
//Agar sum = 2 and array.size() == 0, False, choose karne ko kuch hai hi nahi array mai
// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum)
    {
       int n = arr.size(); 
       int t[n + 1][sum + 1];
       
       for(int i = 0; i < n + 1; i++) //initilization //base condition
       {
            t[i][0]=1;
       }
       
        for(int j=1;j<sum+1;j++){
            t[0][j]=0;
        }
       
       for(int i = 1; i < n + 1; i++)
       {
           for(int j = 1; j < sum + 1; j++)
           {
               if(arr[i - 1] <= j) //if that elememt is smaller or less than the sum then include it
               {
                   t[i][j] = t[i-1][j-arr[i- 1]] || t[i-1][j]; //returns either true or false
               }
               
               else
               {
                   t[i][j] = t[i - 1][j];
               }
           }
        }
        
        return t[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends