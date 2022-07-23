class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    vector<int> ans;
    bool findTarget(TreeNode* root, int k) 
    {
        //APPLY 2 SUM
        bool pos = false;
        inorder(root, ans);
        //now we will traverse the array(in a sorted manner as we did inorder traversa;) and find the pair and return boolean answer
        
        for(int idx1 = 0; idx1 < ans.size(); idx1++)
        {
            for(int idx2 = idx1 + 1; idx2 < ans.size(); idx2++)
            {
                if(ans[idx1] + ans[idx2] == k)
                {
                    pos = true;
                }
                
            }
        }
        
        return pos;
        
    }
};
