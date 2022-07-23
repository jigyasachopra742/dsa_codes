class Solution
{
    //top view mai don't replace the values
        //bottom view mai replace the values
        //Your code here 
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        if(root == NULL) return {};
        //vertial line concept
        vector<int> ans; //initially empty
        queue<pair<Node*, int>> q; //the initial node that is root, and line 0
        map<int, int> mp; //the line and the node, stores values in sorted manner
        
        q.push({root, 0}); //pushing the initial root and initial line 0
        while(q.size() != 0)
        {
            auto curr = q.front(); //get the topmost NODE
            q.pop();
            
            Node* node = curr.first;
            int line = curr.second; 
            //MAKE SURE LINE DOES NOT EXIST IN THE MAP MP
            if(mp.find(line) == mp.end()) //this statement means that if the line is equal to end of map
            //matlan end tak gaya that means it is not there in the map and it is a unique line hence we can use that
            //line
            {
                 mp[line] = node->data;
            }
            
            
            if(node->left)
            {
                q.push({node->left, line - 1});
            }
            
            if(node->right)
            {
                q.push({node->right, line + 1});
            }
        }
        
        for(auto itr : mp)
        {
            ans.push_back(itr.second);
        }
        
        return ans;
    }

};