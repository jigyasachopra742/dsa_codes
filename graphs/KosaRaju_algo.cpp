class Solution
{
	public:
	void rev_dfs(int node, vector<int> &visi, vector<int> transpose[])
	{
	    visi[node] = 1;
	    for(auto itr : transpose[node])
	    {
	        if(!visi[itr])
	        {
	            rev_dfs(itr, visi, transpose);
	        }
	    }
	}
	
	void dfs(int src, stack<int> &st, vector<int> &visi, vector<int> adj[])
	{
	    visi[src] = 1;
	    for(auto itr : adj[src]){
	        if(!visi[itr]){
	            dfs(itr, st, visi, adj);      
	        }
	    }
	    
	    st.push(src);
	}
	//Function to find number of strongly connected components in the graph
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> visi(V, 0);
        //FIRST DO TOPO SORT DFS APPROACH
        
        for(int idx = 0; idx < V; idx++)
        {
            if(!visi[idx]){
                dfs(idx, st, visi, adj);
            }
        }
        
       //AFTER RETURNING OF THE TOPO SORT DO THE TRANSPOSE
       vector<int> transpose[V];
       for(int idx = 0; idx < V; idx++) //TRANSPOSED GRAPH
       {
           visi[idx] = 0; //UNMARK ALL THE NODES AS WE HAVE TO DO REVERSE TOPO DFS
           
           for(auto itr: adj[idx])
           {
               transpose[itr].push_back(idx);
           }
       }
       
       int count = 0;
       while(st.size() != 0)
       {
           int node = st.top();
           st.pop();
           
           if(!visi[node]) //if that node is not visited
           {
               count++;
               rev_dfs(node, visi, transpose);
               
           }
       }
       
       return count;
        //code here
    }
};