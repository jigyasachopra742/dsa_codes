class Solution 
{
public:
    
    bool traverse(TreeNode* root, int targetSum, int sum, bool ans)
    {
        if(root == NULL)
        {
            return ans;
        }
        
        if(ans == true)
        {
            return true;
        }
        
        sum+= root->val;
        if(root->left == NULL && root->right == NULL && sum == targetSum)
        {
            ans =  true;
        }
        
        return traverse(root->left,targetSum, sum, ans)||traverse(root->right,targetSum, sum, ans);
            
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return traverse(root, targetSum, 0, false);
    }
};