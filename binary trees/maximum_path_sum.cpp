/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int calculate(TreeNode* root, int &maxi)
    {
        if(root == NULL)return 0;
        int left_sum = max(0, calculate(root->left, maxi)); //we have initially passes 0 in root because if we get a negative answer in max(root->left, maxi) we should return 0
        int right_sum = max(0, calculate(root->right, maxi));//we have initially passes 0 in root because if we get a negative answer in max(root->right, maxi) we should return 0
        
        maxi = max(maxi, (root->val + left_sum + right_sum));
        return root->val + max(left_sum, right_sum); //YAHA MAXIMUM PATH CHAHIYE
         
        
    }
    
    int maxPathSum(TreeNode* root) 
    {
        
        int maxi = INT_MIN;
        calculate(root, maxi);
        return maxi; //return the maximum path sum 
    }
};