
class Solution {
public:
    //MAIN MOTIVE IS TO SEPRATE THE GRAPHS INTO TWO COMPONENSTS
    //ARTICULATION POINT
    void dfs(vector<int> adj[], int node, int parent, vector<int> &tin, vector<int> &low, vector<int> &vis, int &timer, int n,  vector<vector<int>> &comps)
    {
        vis[node] = 1; //mark the node as visited
        tin[node] = low[node] = timer++; //timer is ++
        int child = 0; //for children nodes in articulation points
        // intially aasign the same timer value to low also 
        
        // bridges condition -> low[v]>disc[u] , that means lowest node
        //reachable from v has timer greater than timer of discoverd time of u. that means 
        // after breaking that edge , it will create more than one components
        
        
        for(auto itr : adj[node]) //for adjacent nodes
        {
            // if not visited then check that compare with the v's lowest 
                // reachble time , as u is reachable to v 
                
                // like this  1->2->3->4->5->1(backedge to 1 )
                //low[5]=1 , so for for4 , low[4]=min(low[4] , low[5])
                // it will update accordingly 
            if(itr == parent) continue; //ghum firke vahi aa gaya
            
            if(!vis[itr]) //if adjacent node is not visited
            {
                dfs(adj, itr, node, tin, low, vis, timer, n, comps); //traversing all the nodes in the tree firstly
                //AFTER COMPLETE DFS TRAVERSAL, DO THE COMPARISONS
                low[node] = min(low[node], low[itr]); //suppose ham last node pe hai vaha se return karna hai for eg agar 12 pe hai uska parent is 11 and uska adjacent is 10 tou 10 ka jo minimum starting time hoga voh 12 lelega and 12 is the adjacent node of 11 which is the parent of 12. Agar 12 ka time < 11 ka time , agar ajacent node ka time will be less than the parent node ka time, then there will be NO bridge
                
                //low[12] = min(low[12], low[10]) => low[12] = low[10] ki value lelega fir voh 11 parent node se compare karega ki bridge banana hai ki nahi 
                // THIS IS THE WHOLE APPROACH FOR BRIDGE IN GRAPHS
               
                if(low[itr] >= tin[node] && parent != -1) //low[12] > low[11] ???
                { //THAT MEANS IT IS A BRIDGE
                    //agar parent == -1 pe break kar doge tou voh ek single component hi ho jaayega, isiliye parent != -1 liya hai
                    
                    comps.push_back({node, itr});
                }
                
                child++;
            }
            
            //AGAR VISITED NIKLA
            else{
                 // 1 -> 2 -> 3 -> 4 -> (backedge to) 1 
                
                //as for 4->1 , 1 is already visited so low[u] = min(low[u] , disc[v])
                //for 4 -: 1 is the lowest timer node that can be get 
                low[node] = min(low[node], tin[itr]);
            }
            
            if(parent == -1 && child > 1)
            {
                comps.push_back({node, itr});
            }
        }
        
       
        
        return;
        
    }
    
    
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) 
    {
        //BRIDGE REMOVAL //CUT EDGE
        //BRIDGES ARE THOSE EDGES ON WHOSE REMOVAL GRAPH BREAKS DOWN INTO DIFFERENT CONPONENTS
        //USE 2 DIFFERENT ARRAYS
        vector<vector<int>> comps;
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
         
        vector<int> adj[n];
        
        for(int i = 0 ; i < edges.size() ; i++)
        {
             int u = edges[i][0];
             int v = edges[i][1];
             
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
        
        vector<int> vis(n, 0);
        
        int timer = 0;
        for(int idx = 0; idx < n; idx++)
        {
            if(!vis[idx])
            {
                dfs(adj, idx , -1, tin, low, vis, timer, n, comps);
            }
        }
        
        return comps;
    }
};

//YEH CORRECT NAHI HAI ISKO KARNA HAI!!!!!!!
