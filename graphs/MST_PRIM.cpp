class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       
      //AGAR V vertices hai tou V - 1 will be edges
        vector<int> wt(V, INT_MAX);
        vector<bool> visit_mst(V, false);

        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        wt[0] = 0; //index 0 pe jo node hogi uska weight 0
        
        pq.push({0, 0}); //0 key value at 0 index for 1st value
        
        while(pq.size() != 0)
        {
            int index = pq.top().second; //ab ham pq se minimum value jaise hi nikalenge usko visit_mast
            //mai true mark kar denge
            pq.pop();
            
            //us particular index pe visit_mast ko mark true kyunki usko hamnei queue se nikal liya hai
            visit_mst[index] = true; //marking minimum value true at index popped
            
            for(auto itr : adj[index]) // ab us index ke adjacent nodes pe jaake minimum weight
            //vala dhundenge//adjacent nodes mai abhi wt ki value pe INT_MAX HAI
            {
                //yeh itr adjacent pair pe traverse kar raha hai
                int value = itr[0];
                int weight = itr[1]; 
                //itr[1] = weight in the adjacent pair
                if(visit_mst[value] == false && wt[value] > weight)
                {
                    
                    wt[value] = weight; //minimum weight is stored instead of INT_MAX in keys array
                    pq.push({wt[value], value});
                    
                }
            }
            
        }
        
        int sum = 0;
        for(int idx = 0; idx < V; idx++)
        {
            sum+= wt[idx];
        }
        
        return sum;
        // code here
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}