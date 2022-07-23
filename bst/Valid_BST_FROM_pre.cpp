class Solution {
public:
    
    void traverse(TreeNode* root, int val)
    {
        if(root == NULL)return;
        
        if(root->left != NULL && val < root->val)
        {
            traverse(root->left, val);
        }
        
        else if(root->left == NULL && val < root->val)
        {
            TreeNode* node = new TreeNode(val);
            root->left = node;
            return;
        }
        
        if(root->right != NULL && val > root->val)
        {
            traverse(root->right, val);
        }
        
        else if(root->right == NULL && val > root->val)
        {
            TreeNode* node = new TreeNode(val);
            root->right = node;
            return;
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
       if(preorder.size() == 0)
       {
           return NULL;
       }
        
       TreeNode* root = new TreeNode(preorder[0]); //1st value of preorder array
    
       for(int idx = 1; idx < preorder.size(); idx++)
       {
           traverse(root, preorder[idx]);
       }
        
       return root;
    }
};