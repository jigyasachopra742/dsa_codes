#include<bits/stdc++.h> 
using namespace std; 

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            //nearly sorted mai ya fir tou mid - 1 , mid , mid + 1 pe ele hoga
            if(nums[mid] == target)
            {
                return mid;
            }
            
            else if(mid - 1 >= left && nums[mid - 1] == target)
            {
                return mid - 1; //pichle index pe ele padha hua hai
                //1st condition is for out of bound
            }
            
            else if(mid + 1 <= right && nums[mid + 1] == target)
            {
                return mid + 1; //agla index pe ele padha hua hai
                //1st condition is for out of bound
            }

            else if(nums[mid] < target)  // Else the element can only be present
        // in right subarray
            {
                left = mid + 2; //left ko uthake right subarray mai rakhdo
            }

            else{ // If element is smaller than mid, then
        // it can only be present in left subarray
                right = mid - 2; //right ko uthake left subarray mai rakhdo
            }
        }
        
        return -1;
    }
};