class Solution {

    public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
        {
            return;
        }
        
        flatten(root->right); //right subtree call
        flatten(root->left); //left subtree call
        
        root->right = prev;
        root->left = NULL;
        
        prev = root;
        
        
    }
};