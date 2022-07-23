#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //t(c) = O(N + E)
    //N = FOR NODES
    //E = FOR ADJACENT NODES
    //s(c) = o(N + E) + O(N) + O(N) //space for adja list, array and queue
    
    //if the adjacent node has been visited earlier and it comes again that means there is a cycle
    
    //if the adjacent node is a parent that has already been visited then that is not a cycle because the next node came from the parent node only so obviously it would have been marked visited
    
    //otherwise if the adjacent node is something that is not a parent and has already been marked visited that means someone marked it earlier that is why there is a cycle
    //next node shloud be marked as visited not thr prev
    //any node other than the prev adajacent node is visited has a cycle
    bool bfs(int src, int V, vector<int> adj[],vector<int>&visited)
    {
        vector<int>parent(V,-1); //starting node will have a prev -1
        queue<int> q;
        
        visited[src] = true;
        q.push(src); //1 is marked is visisted
        
        while(q.size() != 0)
        {
            int curr = q.front();
            q.pop();
            
            for(auto itr : adj[curr])
            {
                //3 -> 5
                if(!visited[itr]) //adjacent node of 3 is 5 which is not visited 
                {
                    visited[itr] = true; //mark 5 visited
                    parent[itr] = curr; //PASS THE CUURENT NODE AS PARENT OF THE ADJACENT NODE
                    //parent[5] = 3
                    q.push(itr); //push(5) in queue q
                }
                
                else if(itr != parent[curr]) //3-> 5
                                                //5-> 3 see here 3 is the parent node of 5
                                                //and 3 is also the adjacent node which is parent 
                                                //node of 5 so here itr(adjacent node) = parent[curr node]
                                                //3 = parent[5] = 3
                
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int> visited(V + 1, false);
        for(int idx = 0; idx < V; idx++)
        {
            if(!visited[idx])
            {
                if(bfs(idx, V, adj, visited))
                {
                    return true;
                }
            }
        }
        
        return false;
        // Code here
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends