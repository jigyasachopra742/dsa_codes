class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) 
    {
        vector<int> dist(V+1, 100000000);
        dist[S] = 0; //distance of source node will be 0
        
        //PERFORM RELAXATION N-1 TIMES
        for(int idx = 1; idx <= V - 1; idx++)
        {
            vector<int> temp;
            int first, second, weight;
            
            for(int j = 0; j < adj.size(); j++)
            {
                temp = adj[j];
                
                first = temp[0];
                second = temp[1];
                weight = temp[2];
                
                if(dist[first] + weight < dist[second]){ //getting the minimum distances 
                    dist[second] = dist[first] + weight;
                }
            }
            
            //NEGATIVE CYCLE KE LIYE DETECT KARNE KE LIYE WE CAN USE ANOTHER LOOP
        }
    
        
        return dist;
        
        // Code here
    }
};