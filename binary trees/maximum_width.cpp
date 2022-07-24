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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)return 0;
        queue<pair<TreeNode*, int>> q; //pair(root, index)
        q.push({root, 0});
        int ans = 0;
        //left index - right index + 1 will give the width 
        while(q.size() != 0)
        {
             int s = q.size();
             int l = q.front().second; //first node ka index in a particular level
             int r = q.back().second; //last node ka index in a particular level
            
            for(int idx = 0; idx < s; idx++)
            {
                auto temp = q.front();
                TreeNode* node = temp.first;
                int level = temp.second; //storing the level(idx)
                q.pop();
                
                if(node->left)
                {
                    q.push({node->left, (long long)2*level + 1});
                }
                
                 if(node->right)
                {
                    q.push({node->right, (long long)2*level + 2});
                }
                
            }
            
             ans = max(ans, (r-l + 1));
            
        }
        
        return ans;
       
    }
};