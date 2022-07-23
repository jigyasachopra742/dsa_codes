class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //use minimum priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //in pair => {dist, node}
        
        vector<int> dist(V + 1, INT_MAX);
        dist[S] = 0;
        
        pq.push({0, S}); //first distance of the initial src node is 0
        //JAISE QUEUE KA STRUCTURE THA BILKUL VAISA HI HAI BAS PRIORITY QUEUE HAI YEH
        //PRIORITY QUEUE MAI HAMESHA TOP HOTA HAI
        //QUEUE MAI HAMESHA FRONT HOTA HAI
        
        while(pq.size() != 0)
        {
            auto curr = pq.top(); //stores a pair of distance and node 
            
            pq.pop();
            //now for adjacent nodes
            for(auto itr : adj[curr.second]) //traversing on the adjacent nodes of the current node
            {
                if(dist[itr[0]] > dist[curr.second] + itr[1]) //purani node ka distance + naye node ka distance
                {
                    dist[itr[0]] = dist[curr.second] + itr[1];
                    pq.push({itr[1], itr[0]}); //distance of the next node and the next node
                }
            }
        }
        
        return dist; // we have to return the distance here
      
        // Code here
    }
};