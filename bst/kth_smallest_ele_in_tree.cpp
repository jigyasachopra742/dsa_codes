class Solution {
public:
    
    void kth(TreeNode* root, int k, vector<int> &ans)
    {
        if(root == NULL)return;
        
        kth(root->left, k, ans);
        ans.push_back(root->val);
        kth(root->right, k, ans);
         
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> ans;
        
        if(root == NULL)
        {
            return 0;
        }
        
        kth(root, k, ans);
        
        return ans[k-1];
        
    }
};