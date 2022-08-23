#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	//PEAK ELEMENT CODE AS IT IS COPY PASTE
	int findMaximum(int nums[], int n) 
	{
	    int low = 0;
        int high = n - 1; //3
        
        if(n == 1)
        {
            return nums[0];
        }
        
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            //edge case
            
            if(mid > 0 && mid < n - 1) //matlab beech mai hai , edge case nahi hai
            {
                if(nums[mid]  > nums[mid - 1] && nums[mid] > nums[mid + 1])
                {
                    return nums[mid]; //we are returning the index of the peak element
                }
    
                //agar aisa nahi hai go to left or right
                else if(nums[mid] < nums[mid + 1]) //jo bhi side badhi ho vaha move karna hai
                {
                    low = mid + 1; //search in right hand side
                }
    
                else
                {
                     high = mid - 1;
                }   
        
            }
            
            //EDGE CASES
            else if(mid == 0) //IF ON 1ST ELE
            {
                if(nums[0] > nums[1])
                {
                    return nums[0]; //0th index has the peak element
                }
                
                else
                {
                    return nums[1]; //1th index has the peak element
                }
            }
            
            else if(mid == n - 1) //agar last ele pe hai
            {
                if(nums[n - 1] > nums[n - 2]) //last ele should be greater than 2nd last ele
                {
                    return nums[n - 1]; //return the last index
                }
                
                else
                {
                    return nums[n - 2]; //return the 2nd last index
                }
            }
         
         
        }
        
        
        return -1;  
        
	    // code here
	    
	}
};