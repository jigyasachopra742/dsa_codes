class Solution {
public:
    
    void solve(vector<vector<char>>& grid, vector<vector<bool>> &visi, int row, int col)
    {
        //condition for checking in board
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0' || visi[row][col] == true)
        {
            return; //khali return kar dungi
        }
        
        visi[row][col] = true; //mark it as true
        
        solve(grid, visi, row - 1, col); //top
        solve(grid, visi, row, col + 1); //right
        solve(grid, visi, row, col-1); //bottom
        solve(grid, visi, row + 1, col); //left
    
    }
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visi(n, vector<bool> (m , false));
        
        for(int idx1 = 0 ; idx1 < n; idx1++) //row
        {  
            for(int idx2 = 0; idx2 < m; idx2++) //column
            {
                if(grid[idx1][idx2] == '1' && visi[idx1][idx2] == false){
                   
                    
                    solve(grid, visi, idx1, idx2); //iske return ke baad count chalega
                    count++; //jitni baar call karke solve hokar return hoke aayega utni 
                    
                }
            }
        }
        
        return count;
    }
};