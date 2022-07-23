#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[])
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto itr : adj[node])
        {
            if(!vis[itr])
            {
                if(dfs(itr, vis, dfsVis, adj)) return true;
            }
            
            else if(dfsVis[itr])
            {
                return true;
            }
        }
        
        dfsVis[node] = 0; //vapis aate hue unmark
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<int> vis(V + 1, 0); //UNMARKED
        vector<int> dfsVis(V + 1, 0); //UNMARKED
        
        for(int idx = 0; idx < V; idx++)
        {
            if(!vis[idx])
            {
                if(dfs(idx, vis, dfsVis, adj)) return true;
            }
        }
        
        return false;
        // code here
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends