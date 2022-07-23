#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //ismei sabse phele ham indegree calculate karenge for each node and jiski indegree 0 hogi push that in queue and traverse the adjacent nodes level order wise since it is BFS and make indegree of other nodes as well 0 and push them on queue
	     vector<int>ind(V,0);
	   queue<int>q;
	    for(int i=0;i<V;i++) //har ek vertex pe traverse karne ke liye
	    {
	        for(auto it:adj[i]) //particular vertex ke adjacent node pe traverse karne ke liye
	        {
	            ind[it]++;
	            
	        }
	    }
	   
	   for(int i=0;i<V;i++)
	    {
	        if(ind[i]==0)
	        q.push(i);
	    }
	   vector<int>v;
	   while(!q.empty())
	   {
	       int node=q.front();
	       q.pop();
	       v.push_back(node);
           
	       for(auto it:adj[node])
	       {
	           ind[it]--;
	           if(ind[it]==0)
	           q.push(it);
	       }
	   }
	   
	   return v;
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