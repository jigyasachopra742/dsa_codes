class Solution {
public:
    
    bool dfs(int src, vector<vector<int>>& graph, int n, vector<int> &color)
    {
        //EVRRY NODE SHOULD HAVE DIFFERENT COLOURS
        
        if(color[src] == -1) color[src] = 0; //marked
        
        for(int itr : graph[src])//now iterate on neighbour(adjacent nodes)
        {
            if(color[itr] == -1) //not marked
            {
                color[itr] = 1 - color[src]; //FOR DIFFERENT COLORS ON DIFFERENT NODES
                //SO THAT DEFINATION OF BIPARTITE IS MAINTAINED
                
                if(!dfs(itr, graph, n, color)) //call again //yeh next nodes ko bhejne ke liye call bhi hai//this loop will go till end of the tree
                {
                    return false;
                }
            }
            
            else if(color[itr] == color[src]) //if the adjacent node has the same color as that of parent node it is not a BIPARTITE
            {
                return false;
            }

        }
        
        return true;
        
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        //DFS
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int idx = 0; idx < n; idx++)
        {
            if(color[idx] == -1) //not marked 
            {
                if(!dfs(idx, graph, n, color)){
                    return false;
                }
            }
        }
        
        return true;
    }
};