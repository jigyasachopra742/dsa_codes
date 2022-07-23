class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int height1 = maxDepth(root->left);
        int height2 = maxDepth(root->right);
        
        int max_height = max(height1, height2) + 1;
        return max_height;
    }
};