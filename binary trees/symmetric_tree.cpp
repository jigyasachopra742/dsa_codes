class Solution 
{
public:
    
    bool traversal(TreeNode* p , TreeNode* q)
    {
        if(p == NULL && q == NULL)
        {
            return true;
        }
        
        if(p == NULL || q == NULL)
        {
           return false; 
        }
        
        bool left = traversal(p->left , q->right);
        bool right = traversal(p->right , q->left);
        
        if(left == false || right == false)
        {
            return false;
        }
        
        if(p->val == q->val)
        {
            return true;
        }
        
        return false;
}
    
    
    
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
        {
            return false;
        }
        
        return traversal(root->left , root->right);
    }
};