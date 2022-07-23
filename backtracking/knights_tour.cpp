#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<int>>&maze, int n)
{
    for(int row = 0 ; row < n ; row++)
    {
        for(int col = 0 ; col < n ; col++)
        {
            cout << maze[row][col] <<" ";
        }
        cout <<"
";
    }
    cout<<endl;
}

void printKnightsTour(int n , vector<vector<int>>& maze , int rows , int cols , int val)
{
    if(rows < 0 || cols < 0 || rows >= n|| cols >= n || maze[rows][cols] != 0)
    {
        return;
    }
    
    maze[rows][cols] = val;
    
    if(val == n*n)
    {
        display(maze , n);
    }
    val++;
    
    printKnightsTour(n , maze , rows - 2 , cols + 1 , val);

    printKnightsTour(n , maze , rows - 1 , cols + 2 , val);
        
    printKnightsTour(n , maze , rows + 1 , cols + 2 , val);
        
    printKnightsTour(n , maze , rows + 2 , cols + 1 , val);
 
    printKnightsTour(n , maze , rows + 2 , cols - 1 , val);
    
    printKnightsTour(n , maze , rows + 1 , cols - 2 , val);
  
    printKnightsTour(n , maze , rows - 1 , cols - 2 , val);
    
    printKnightsTour(n , maze , rows - 2 , cols - 1 , val);
    
    maze[rows][cols] = 0;
     

}

int main()
{
   vector<vector<int>> maze;        //2d array using vector
   
   int n , rows , cols;
   
   cin >> n >> rows >> cols;
   
   for(int row = 0 ; row < n ; row++)
   {
       vector<int> ans;
       for(int col = 0; col < n ; col++)
       {
           ans.push_back(0);
       }
       
       maze.push_back(ans);
   }
    
    printKnightsTour(n , maze , rows , cols , 1);

}