#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(int row, bool graph[101][101], int color[], int n, int col)
{
    for(int k = 0; k < n ; k++)
    {
        if(k != row && graph[k][row] == 1 && color[k] == col) //if k != row means it is the different node 
        //graph[k][row] == 1 that means it is the adjacent node and color[k] == col means if the color at that node 
        //is same as the color of the prev node then return false
        {
            return false;
        }
    }
    
    return true;
}

bool helper(int row, bool graph[101][101], int m, int n, int color[])
{
    if(row == n) //m is colors, n is total nodes in graph
    {
        return true; //agar end tak jaata hai matlab sab nodes use ho 
        //gaye matlab sab nodes pe colors aa gaye different 
    }
    //we will able to successfully color all the nodes that's why we reached the end node and
    //returned true
    
    for(int col = 1; col <= m ; col++) //m colors tak  at most 
    {
        if(isSafe(row, graph, color, n, col)) //agar adjacent colors pe different color hai
        {
            color[row] = col; //attach the color 1, 2 or 3 at most colors
            //if we get true by that particular color then we do not have to do recursive calls again
   /*next node*/         if(helper(row + 1, graph, m, n, color)) return true; //going to the next node
            color[row] = 0; //backtracking agar helper function false return karta then backtrack mark 0
        }
    }
    
    return false;
}



bool graphColoring(bool graph[101][101], int m, int n) 
{
    //NQUEENS
    int color[n] = {0}; //== {0} means none of the nodes have been assigned colors
    if(helper(0, graph, m, n, color)) return true; //starting from the first node
    return false;
    // your code here
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends