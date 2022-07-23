class Solution 
{
public:
    
     int count = 0;
     bool isSafe(vector<vector<int>> arr , int row , int col )
    {
        for(int curRow = row - 1 ; curRow >= 0 ; curRow--) //center
        {
            if(arr[curRow][col] == 1)
            {
                return false;
            }
        }
        for(int curRow = row - 1, curCol = col - 1; curRow >=0 && curCol >= 0; curRow--, curCol--) //left diagonal
        {    
            if(arr[curRow][curCol] == 1) 
            {
                return false;
            }
        }
        
        for(int curRow = row - 1, curCol = col + 1; curRow >=0 && curCol < arr[0].size(); curRow--, curCol++) //right diagonal
        {
            if(arr[curRow][curCol] == 1)
            {
                return false;
            }
        }
        
        return true;
    }
    
    void nQueens(vector<vector<int>> arr , int row)
    {
        if(row == arr.size())
        {
            count++;
            
            return;
        }
         
        for(int col = 0 ; col < arr.size() ; col++)
        {
            if(isSafe(arr , row , col))
            {
                arr[row][col] = 1; //safe
                nQueens(arr , row + 1);
            }
            
            arr[row][col] = 2;  //unsafe

         }
        
        return;
    }
    
    
    int totalNQueens(int n) 
    {
        vector<vector<int>>arr; //2d vector
        
        for(int idx1 = 0 ; idx1 < n ; idx1++)
        {
            vector<int>ans;
            
            for(int idx2 = 0 ; idx2 < n ; idx2++)
            {
                ans.push_back(0);
            }
            
            arr.push_back(ans);
        }
        
        nQueens(arr , 0);
        
        return count;
    }
};