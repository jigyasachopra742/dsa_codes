class Solution 
{
public:
    
    int count =0 ;
    
    void pre_order(TreeNode* root ,int value)
    {
        if(root != NULL)
        {
            if(root->val >= value)
            {
                count++;
                value = root->val;
            }
            
            pre_order(root->left , value);
            pre_order(root->right , value);
        }
    }
    
    int goodNodes(TreeNode* root) 
    {
        
        pre_order(root , root->val);
        return count;
        
        
    }
};