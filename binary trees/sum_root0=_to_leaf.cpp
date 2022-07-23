class Solution 
{
    
public:
    
    int ans = 0;
    
    void traverse(TreeNode* root , int val) //3, 1
    {
        if(root == NULL)
        {
            return;
        }
        
        val = val * 10; //val = 1 * 10 = 10
        val+= root->val; //val = 1 + 3 = 13
        
        if(root->left == NULL && root->right == NULL)
        {
            ans+= val; //ans = 12 + 13 = 23
        }
        
        traverse(root->left, val); //2
        traverse(root->right, val); //3, 1
    }
    int sumNumbers(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        
        traverse(root , 0);
        return ans;
    }
};