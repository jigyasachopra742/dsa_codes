class Solution {
public:
    
    bool solve(int src, vector<int> &color, vector<vector<int>> &graph)
    {
        queue<int> q;
        q.push(src);
        color[src] = 1; //mark the color of src node as 1 like we used to mark visited of src node
        
        while(q.size() != 0)
        {
            int node = q.front();
            q.pop();
            
            for(int itr : graph[node]) //adjacent nodes
            {
                if(color[itr] == -1) //if color is not marked
                {
                    color[itr] = 1 - color[node]; //adjacent node ka opposite color chahiye apne current(parent) node se
                    q.push(itr);
                }
                
                else if(color[itr] == color[node]){ //if color is already marked and not opposite
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int idx = 0 ; idx < n; idx++)
        {
            if(color[idx] == -1)
            {
                if(!solve(idx, color, graph)){
                    return false;
                }
            }
        }
        
        return true;
    }
};