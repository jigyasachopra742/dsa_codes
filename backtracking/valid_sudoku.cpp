class Solution 
{
public:
    
    int safe_place(vector<vector<char>>& board , int row , int col)
    {
        char ch = board[row][col];
        
        int rowidx = 3 * (row/3) , colidx = 3 * (col/3);
        
        for(int idx = 0 ; idx < 9 ; idx++)
        {
            if(board[row][idx] == ch && idx != col) //row
                return 0;  //idx mai voh usi column mai check nahi karega
            
            if(board[idx][col] == ch && idx != row) //column
                return 0;
            
            if(board[rowidx + (idx/3)][colidx + (idx % 3)] == ch && (rowidx + (idx/3)) != row && (colidx + (idx % 3)) != col ) //grid
                return 0; //2nd condition is for repetition
        }
        
        return 1;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        
        for(int row = 0 ; row < 9 ; row++)
        {
            for(int col = 0 ; col < 9 ; col++)
            {
                if(board[row][col] != '.')
                { 
                    int ans = safe_place(board , row , col);
                    if(ans == 0)
                    {
                        return false;
                    }
                }
                    
            }
        }
        
        return true;
        
    }
    
};