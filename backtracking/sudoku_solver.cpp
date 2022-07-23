class Solution {
public:
    
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch)
    {
            for(int i = 0; i < 9; i++)
            {
                if(board[i][col] == ch)
                {
                    return false;
                }



                if(board[row][i] == ch)
                {
                    return false;
                }


                if(board[3 * (row/3) + i /3][3 * (col/3) + i%3] == ch)
                {
                    return false;
                }
            }
        
           
        return true;   
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0 ; col < board[0].size(); col++)
            {
                if(board[row][col] == '.') //empty //agar full nahi hai
                {
                    for(char ch = '1'; ch <= '9'; ch++)
                    {
                        if(isSafe(board, row, col, ch))
                        {
                            board[row][col] = ch;
                            
                            if(solve(board))
                            {
                                return true; //break and return 
                            }
                            
                            else
                            {
                               board[row][col] = '.';  
                            }
                              
                        }
                    }
                    
                    return false;
                }
               
            }
        }
        
        return true; //it returns true at the end because it has filled up everything because when the table does not returns true or even false , it returns true at the end that means if it is not returning anything from upar it returns true at the end that means the table is filled up and all the cases were VALID (SUDOKU IS READY)
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};