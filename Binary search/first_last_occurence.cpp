#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
        int firstidx(vector<int>& nums,int target)   //binary search made for first index
        {
            int low=0 , high = nums.size() - 1, mid , result = -1;
    
            while( low <= high )  //first occurence 
            {
                mid = low + ( high - low ) / 2 ;
        
                if( target == nums[mid] )
                {
                    result = mid;
                   
                    high = mid - 1;  //if found then this line is written to check wheather that number is present 
                }                    // before that or not

                else if( target < nums[mid])
                {
                   high = mid - 1;
                }

                else
                { 
                    low = mid + 1;
                }
            }

            return result;
        }

        int lastidx(vector<int>& nums, int target ) //it tells the lastindex
        {
            int low=0 , high = nums.size() - 1, mid , result = -1 ;

            while( low <= high )
            {
                    mid = low + ( high - low ) / 2 ;

                    if( target == nums[mid])
                    {
                        result = mid;
                        
                        low = mid + 1;  //if found then this line is written to check wheather that number is present 
                            //after that or not
                    }

                    else if( target < nums[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    { 
                        low = mid + 1;
                    }
    
            }

            return result;
        }


    vector<int> searchRange(vector<int>& nums, int target)
    {
    
        int fidx = firstidx(nums,target) ;   //calling first index function
    
        int lidx =  lastidx(nums,target);  //calling last index function
    
        return {fidx,lidx};
    }
};
   
    