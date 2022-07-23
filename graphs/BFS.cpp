class Solution {
  public:
  
  //BFS IS TRAVERSING ALL THE ADJACENT NODES AND THEN GOING TO NEXT LEVEL
  //DFS IS COMPLETELY EXPLORING THE NODES ON WHICH WE ARE, GOING IN DEPTH TILL WE DO NO GET IT'S NEIGHBOURS
  //BEST WAY OF CONSTRUCYTING A GRAPH TREE IS TO MAKE AN ADJACENCY LIST, STORE ALL THE ADJACENT NODE
  //AND CREATE A LIST WITH INDEXES AND JAISE HI ELEMENTS AATE JAAYE MARK THEM VISITED IN THE LIST
  
  //Remove, mark, print, add adjacent nodes
    // Function to return Breadth First Traversal of given graph.
    
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int> ans;
        vector<bool> visited(V+1, false);
        
        for(int idx = 0; idx < V; idx++)
        {
            if(!visited[idx])
            {
                queue<int> q;
                q.push(idx); //push the src node in queue that is 0 is pushed first
                //jaise hi queue mai src node pysh gua voh vase hi mark ho gaya taaki vapis se usko use na kar sake
                visited[idx] = true;
                while(q.size() != 0)
                {
                    auto curr = q.front(); //remove
                    q.pop();
                    
                    ans.push_back(curr); //print
                    
                    for(auto itr : adj[curr]) //for adjacent nodes of src
                    {
                        if(!visited[itr])
                        {
                            q.push(itr); //push the adjacent nodes in queue;
                            visited[itr] = true;
                        }
                    }
                    
                    
                }
                
            }
        }
        
        return ans;
    }
};