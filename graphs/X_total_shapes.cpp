class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>> &visi)
    {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || 
        grid[row][col] == 'O' || visi[row][col] == true)   
        
        {
            return;
        }
        
        visi[row][col] = true;
        
        dfs(row - 1, col, grid, visi);
        dfs(row, col + 1, grid, visi);
        dfs(row + 1, col, grid, visi);
        dfs(row, col - 1, grid, visi);
        
    }
    
    
    int xShape(vector<vector<char>>& grid) 
    {
        int count = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visi(n, vector<bool> (m , false));
        
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(grid[row][col] == 'X' && visi[row][col] == false)
                {
                    count++;
                    dfs(row, col, grid, visi);
                    
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends