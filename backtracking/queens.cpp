class Solution {
public:
    //sabswe phele rows li unke columns mai check kiya
    bool isSafe(vector<string> &arr, int row, int col, int &n)
    {
        //vertically
        for(int currow = row - 1; currow >= 0; currow--)
        {
            if(arr[currow][col] == 'Q')
            {
                return false;
            }
        }
        
        for(int currow = row - 1, currcol = col - 1; currow >= 0 && currcol >= 0; currow--, currcol--)
        {
             if(arr[currow][currcol] == 'Q')
            {
                return false;
            }
        }
        
        for(int currow = row - 1, currcol = col + 1; currow >= 0 && currcol < n; currow--, currcol++)
        {
             if(arr[currow][currcol] == 'Q')
            {
                return false;
            }
        }
        
        return true;
        
    }
    
    
    void nQueen(vector<vector<string>> &result,vector<string> &arr, int row, int &n)
    {
        if(row == n)
        {
            result.push_back(arr);
            return;
        }
        
        for(int col = 0; col < n; col++)
        {
            if(isSafe(arr, row, col, n))
            {
                arr[row][col] = 'Q';
                nQueen(result, arr, row + 1, n); //recursion
               
            }
            
             arr[row][col] = '.'; //backtracking
                
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> result;
        
        vector<string> arr(n, string(n, '.')); //n size, initializing with . //2d vector
        nQueen(result, arr, 0, n);
        return result;
        
        
    }
};