#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
       int left=0;
        
       int right=nums.size()-1;
        
       while(left<=right)
       {
           int mid=left+(right-left)/2;
           
           if(nums[mid]==target)
           {
               return mid;
           }
           
           if(nums[left]==target)
           {
               return left;
           }
           
           if(nums[right]==target)
           {
               return right;
           }
           if(nums[left]<=nums[mid]) //4 <= 7
           {
               if(target<nums[mid]&&target>nums[left])
                  
                   right=mid-1;
               else
                    left=mid+1;
           }
           else 
           {
               if(target<nums[right]&&target>nums[mid])
                   left=mid+1;
               else
                   right=mid-1;
           }
       }
       return -1;
        
        
        
        
    }
};