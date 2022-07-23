class Solution {
public:
    //LEVEL ORDER linewise zig zag ODD LEVEL MAI SEEDHA LOOP
    //EVEN LEVEL PE ULTA LOOP
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }
        //flag = 0: l->r
        //flag = 1: r->l
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        
        int count = 0;
         
            
        while(q.size() != 0)
        {
            int size = q.size();
            vector<int> level;
            
            for(int idx = 0 ; idx < size; idx++) //works for every iteration
            {
                auto curr = q.front();
                q.pop();
                
                //PREORDER METHOD
                level.push_back(curr->val); //for every iteration we push the parent node and then we look for it's children in left subtree and right subtree
                if(curr->left)
                {
                    q.push(curr->left);
                }
                
                if(curr->right)
                {
                    q.push(curr->right);
                }
                
            }
            
            if(count % 2 == 0)
            {
                result.push_back(level); //LEVEL IS 1D ARRAY
            }
            
            else
            {
                 reverse(level.begin(), level.end()); //ELSE REVERSED ARRAY BHEJO
                 result.push_back(level);
            }
            
            level.clear();
            
            count++; //HAR EK LEVEL KE BAAD COUNT++ KARO
        }
        
        return result;
    }
};