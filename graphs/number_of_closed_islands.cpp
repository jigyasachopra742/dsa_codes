class Solution {
    public:
    
    void change(vector<vector<int>>& matrix, int i, int j)
    {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == 0)
        {
            return;
        }
        //jo land boundary se touched hai voh nahi chahiye
        matrix[i][j] = 0;  //CHANGE THE BOUNDARY ONES TO 0
        
        change(matrix, i - 1, j);
        change(matrix, i, j + 1);
        change(matrix, i + 1, j);
        change(matrix, i, j - 1);
        
    }
    
    int count = 0;
    int closedIslands(vector<vector<int>>& matrix, int N, int M) 
    {
        if(matrix.size() == 0)return 0;
        
        //BOUNDARY TRAVERSAL
        for(int j = 0; j < M; j++)
        {
            if(matrix[0][j] == 1)
            {
                change(matrix, 0, j); //CHANGE THE BOUNDARY ONES TO 0
            }
            
            if(matrix[N - 1][j] == 1)
            {
                change(matrix, N - 1, j); //CHANGE THE BOUNDARY ONES TO 0
            }
            
        }
        
        for(int i = 0; i < N; i++)
        {
            if(matrix[i][0] == 1)
            {
                change(matrix, i, 0); //CHANGE THE BOUNDARY ONES TO 0
            }
            
            
            if(matrix[i][M - 1] == 1)
            {
                change(matrix, i, M - 1); //CHANGE THE BOUNDARY ONES TO 0
            }
        }
        
        //phele saare boundary ko water mai change karo
        //fir grid ke andar dekho and count++
        
        //AFTER THE DFS TRAVERSAL
        //all the boundary lands have been to changed to water
        //ab grid ke andar kitne land bach gaye unpe traversal karooooooo
        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < M; col++)
            {
                if(matrix[row][col] == 1) //within grid
                {
                    count++; //grid vale
                    change(matrix, row , col); //CALCULATE //aise kitne land bach gaye jo paani se ghire hue hai
                }
            }
        }
        
        return count;
        // Code here
    }
};