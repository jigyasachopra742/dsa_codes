#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int start = 0;
        int end = rows*cols -1;
        
        while(start <= end)
        {
            int mid = start+(end - start)/2;
            
            int row  = mid/cols;
            int col = mid%cols;
            
            int m = matrix[row][col];
            
            if(m == target)
                return true;
            else if(m > target)
            {
                end = mid - 1 ;
            }
            else
            {
                start = mid + 1;
            }
                
        }
        
        return false;
        
    }
};