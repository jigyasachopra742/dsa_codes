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
    
    bool isb = true;
    int calculate(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int lh = calculate(root->left);
        int rh = calculate(root->right);
        
        if(isb)
        {
            int gap = abs(lh - rh);
            if(gap > 1)
            {
                isb = false;
            }
            
          
        }
        
        return lh >= rh ? lh + 1 : rh + 1;
    }
    bool isBalanced(TreeNode* root) 
    {
        calculate(root);
        if(isb == true)
        {
            return true;
        }
        
        return false;
    }
};