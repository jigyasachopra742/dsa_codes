#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int src, stack<int> &st, vector<int> adj[], vector<bool> &visi)
	{
	    visi[src] = true;
	    for(int itr : adj[src])
	    {
	        if(!visi[itr])//if adjacent not visited
	        {
	            dfs(itr, st, adj, visi);
	        }
	    }
	    
	    st.push(src); //AFTER THE DFS CALLS ARE OVER PUSH THOSE NODES IN STACK TAAKI DAG LAGE
	    //LIFO
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //DFS
	    //WHEN DFS OF A NODE IS OVER PUSH IT IN STACK
	    vector<int> ans;
	    stack<int> st;
	    vector<bool> visi(V+1, false);
	    
	    for(int idx = 0; idx < V; idx++)
	    {
	        if(!visi[idx]){
	            dfs(idx, st, adj, visi);
	        }
	    }
	    
	    while(st.size() != 0)
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	    // code here
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends