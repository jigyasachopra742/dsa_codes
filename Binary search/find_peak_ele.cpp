#include<bits/stdc++.h> 
using namespace std; 

class Solution 
{
public:
    //mid peak ele hai ki nahi yeh search karna hai 
    int findPeakElement(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size() - 1; //3
        
        if(nums.size() == 1) //iski na likne ki wajah se runtime aa gaya tha
        {
            return 0; //0th index vala ele hi return kardo
        }
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            //edge case
            
            if(mid > 0 && mid < nums.size() - 1) //matlab beech mai hai , edge case nahi hai
            {
                if(nums[mid]  > nums[mid - 1] && nums[mid] > nums[mid + 1])
                {
                    return mid; //we are returning the index of the peak element
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
                    return 0; //0th index has the peak element
                }
                
                else
                {
                    return 1; //1th index has the peak element
                }
            }
            
            else if(mid == nums.size() - 1) //agar last ele pe hai
            {
                if(nums[nums.size() - 1] > nums[nums.size() - 2]) //last ele should be greater than 2nd last ele
                {
                    return nums.size() - 1; //return the last index
                }
                
                else
                {
                    return nums.size() - 2; //return the 2nd last index
                }
            }
        }
        
        return -1;
    }
};