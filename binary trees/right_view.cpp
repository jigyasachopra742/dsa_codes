class Solution {
public:
    
    void rightSide(TreeNode* root, vector<int> &array, int level)
    {
        if(root == NULL)return;
        
        if(level == array.size())
        {
            array.push_back(root->val);    
        }
        
        rightSide(root->right, array, level + 1);
        rightSide(root->left, array, level + 1);
        
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        int level;
        vector<int> array;
        rightSide(root, array, 0);
        return array;
    }
};