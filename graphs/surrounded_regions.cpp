class Solution {
public:
    
   
    void solve(vector<vector<char>>& board) 
    {
        //SIRF JO GRID KE ANDAR 'O' HAI UNKO 'X' MAI CHANGE KARNA HAI
        //JO GRID SE BAHAR JAA RAHE UNKO PHELE '#' MAI CONVERT KARO THEN BACK TO 'O'
        int m = board.size();
        int n = board[0].size();
        
        //FIRST TRAVERSE ON THE BOUNDARIES TO CHANGE 'O' TO '#'
        if(board.size() == 0)return;
        
        //FOR BOUNDARY ROWS
        for(int j = 0 ; j < n; j++) //changing columns
        {
            if(board[0][j] == 'O')
            {
                dfs(board, 0, j); //board, i, j //locations on board //first row
            }
            
            if(board[m - 1][j] == 'O')
            {
                dfs(board, m - 1, j); //last row
            }
        }
        
        //FOR BOUNDARY COLUMNS
        for(int i = 0; i < m; i++) //changing rows
        {
            if(board[i][0] == 'O')
            {
                dfs(board, i, 0); //first column
            }
            
            if(board[i][n - 1] == 'O')
            {
                dfs(board, i, n - 1); //last column
            }
        }
        
        //NOW TRAVERSE FOR GRID AFTER THE DFS COMPLETION 
        
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(board[row][col] == '#') //for boundar ones
                {
                    board[row][col] = 'O'; //YEH VOH VALE HAI TOU BOUNDARY SE BAHAR JAA RAHE
                    //INKO 'X'  MAI CHANGE NAHI KARNA HAI
                }
                
                else if(board[row][col] == 'O') //for those 'O' which are in GRID
                    //WHO ARE NOT GOING OUTSIDE THE BOUNDARY
                {
                    board[row][col] = 'X'; 
                }
            }
        }
        
        return;
    
    }
    
     void dfs(vector<vector<char>>& board, int i, int j)
    {
        //i = row
        //j = column
        //HERE WE ARE CHANGING BOUNDARY 'O' TO '#'
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
        {
            return;
        }
        
        board[i][j] = '#'; 
        //fir boundary 'O' ke aas paas dekho kon kon se aur 'O' hai
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};