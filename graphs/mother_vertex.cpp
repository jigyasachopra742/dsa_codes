class Solution 
{
    public:
    //IN undirected connected graph, all vertices are mother vertices as we can reach 
    //to all other nodes in the graph
    
    //in undirected disconnected graphm there is no mother vertex as we cannot reach to all 
    //other nodes in the graph
    
    //in directed connected graph, we have to find vertex v such that we can reach all other nodes
    //in the graph through a directed graph
    
    //Function to find a Mother Vertex in the Graph.
    //T(C) : O(V + E)
    void dfs(int src, vector<int> &visi, vector<int> adj[])
	{
	    visi[src] = 1;
	    for(auto itr : adj[src]){
	        if(!visi[itr]){
	            dfs(itr, visi, adj);      
	        }
	    } //IN DFS LAST NODE IS ALWAYS THE SOURCE NODE
	    
	    
	}
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int ans = 0; //TO STORE THE LAST FINSIHED VERTEX(MOTHER VERTEX)
	    vector<int> visi(V, 0);
        //FIRST DO TOPO SORT DFS APPROACH
        
        for(int idx = 0; idx < V; idx++)
        {
            if(!visi[idx])
            {
                dfs(idx, visi, adj); //DO THE TRAVERSAL AND FIND LAST FINISHED VERTEX
                ans = idx; //LAST FINSIHED VERTEX STORED IN ANS
            }
        }
        
        //NOW WE CHECK IF v IS ACTUALLY A MOTHER VERTEX(OR GRAPH HAS A MOTHER VERTEX).
        //WE BASICALLY CHECK WHETHER EVERY VERTEX IS REACHABLE FROM v OR NOT.
        //RESET ALL THE VERTICES AS FALSE AND DO DFS FROM v TO CHECK ALL VERTICES ARE
        //REACHABLE OR NOT
        
        fill(visi.begin(), visi.end(), false);//The 'fill' function assigns the value 'val' 
        //to all the elements in the range [begin, end), where 
        //'begin' is the initial position and 'end' is the last position.
        
        dfs(ans, visi, adj);  //START DFS FROM 6 AND MARK ALL VISITED
        for(int idx = 0; idx < V; idx++)
        {
            if(visi[idx] == false)
            {
                return -1;
            }
        }
        
        
        
        return ans;
	    // Code here
	}

};