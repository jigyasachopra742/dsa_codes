class Solution {
  public:
    vector <int> bottomView(Node *root) 
    {
        vector<int> ans;
        if(root == NULL) return {};
        
        map<int, int> mp; //first pe line and second pe value us line pe
        
        queue<pair<Node*,int>> q; //node and line ka pair
        
        q.push({root, 0}); //node and level 0
        
        //whatever line we are getting just replae by that node in map
        
        while(q.size() != 0)
        {
            auto itr = q.front();
            q.pop();
            
            Node* node = itr.first; //root of queue pair
            int line = itr.second; //level of queue pair
            mp[line] = node->data; //us particular line pe data is stored
            
            if(node->left)
            {
                q.push({node->left, line - 1});
                
            }
            
            if(node->right)
            {
                q.push({node->right, line + 1});
                
            }
        }
        
        for(auto it : mp)
        {
            ans.push_back(it.second); //gives the value
        } //kyunki ham line pe data store kar rahe that is second paramter in map
        
        return ans;
        // Your Code Here
    }
};