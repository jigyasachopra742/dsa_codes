class Solution 
{
public:
    
    int ans  = INT_MAX;
    void helper(TreeNode* root, int height)
    {
        
        if(root == NULL)return;
        
        helper(root->left, height + 1);
        helper(root->right, height + 1);
        
        if(root->left == NULL && root->right == NULL)
        {
            ans = min(ans, height);
        }
    }
        
    int minDepth(TreeNode* root) 
    {
        if(root == NULL)return 0;
        
        helper(root, 1);
        return ans;
        
        
    }
};