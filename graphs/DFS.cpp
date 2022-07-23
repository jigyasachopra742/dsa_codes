#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(int src, vector<int> adj[], vector<bool> &visited, vector<int>&ans)
    {
        ans.push_back(src); //push the src vertices in ans array
        visited[src] = true;
        for(auto it : adj[src])
        {
            if(!visited[it])
            {
                solve(it, adj, visited, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int>ans;
        vector<bool> visited(V+1, false);
        for(int idx = 0; idx < V; idx++)
        {
            if(!visited[idx])
            {
                solve(idx, adj, visited, ans);
            }
        }
           
        return ans; // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends