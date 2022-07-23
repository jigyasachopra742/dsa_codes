#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        //BFS TOPO SORT
        vector<int> ind(V+1, 0);
        queue<int> q;
        
        for(int idx = 0; idx < V; idx++)
        {
            for(auto itr : adj[idx])
            {
                ind[itr]++;
            }
        }
        
        for(int idx = 0; idx < V; idx++)
        {
            if(ind[idx] == 0) //sare vertices ki indegree is calcualted
            {
                q.push(idx);
            }
        }
        
        int count = 0;
        while(q.size() != 0)
        {
            auto curr = q.front();
            q.pop();
            count++;
            for(auto itr : adj[curr])
            {
                ind[itr]--;
                if(ind[itr] == 0)
                {
                    q.push(itr);
                }
            }
        }
        
        if(count == V) return false; //agar count == V hua matalb ki saare vertices aa gaye 
        //acc to topo sort and topo sort mai kabhi bhi cycle nahi hota that is why false
        return true; // otjerwise true
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