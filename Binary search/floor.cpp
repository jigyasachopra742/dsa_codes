#include<bits/stdc++.h> 
using namespace std; 

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x)
    {
        long long start = 0;
        long long end = n - 1;
        long long ans = -1;
        
        while(start <= end)
        {
            long long mid = start + (end - start)/2;
            if(v[mid] == x)
            {
                return mid; //return the mid index
            }
            
            else if(v[mid] < x) //can be a possible answer
            {
                ans = mid;
                start = mid + 1; //kyunki ele right half mai present hai
            }
            
            else //do not update answer
            {
                end = mid - 1;
            }
            
        }
        
        return ans;
        // Your code here
        
    }
};