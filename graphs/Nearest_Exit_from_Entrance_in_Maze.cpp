#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int row = maze.size();
        int col = maze[0].size();
        
        queue<pair<int, pair<int, int>>> q; //BFS APPROACH
        //DISTANCE, ROW, COL
        vector<vector<int>> dist(row, vector<int>(col, 1e9)); //minimum distance stored
          //entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at
        int startrow = entrance[0]; 
        int startcol = entrance[1];
       
        dist[startrow][startcol] = 0; //source ka dist is 0
        
        int rows[] = {-1, 0, +1, 0}; //traversing in all the 4 directions
        int cols[] = {0, +1, 0, -1};
        
        q.push({0, {startrow, startcol}}); //q.push(dist, (row, col))
        while(q.size() != 0)
        {
            int steps = q.front().first; //dist
            int r = q.front().second.first; //row
            int c = q.front().second.second; //column
            q.pop(); 
            
            for(int i = 0; i < 4; i++)
            {
                int nrow = r + rows[i];
                int ncol = c + cols[i];
                
                if(nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && maze[nrow][ncol] == '.' && steps + 1 < dist[nrow][ncol])
                {
                    if(nrow == 0|| ncol == 0 || nrow == row - 1 || ncol == col - 1) //destination (exit) condition
                    {  //at border of maze
                        return steps + 1; // number of steps in the shortest path from the entrance to the nearest exit
                    }
                    
                    dist[nrow][ncol] = steps + 1;
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
    
        return -1;    
    }
};