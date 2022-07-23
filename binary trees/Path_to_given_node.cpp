class Solution 
{
public:
    
    void traverse(TreeNode* root , vector<string>& array , string str)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            str+= to_string(root->val);
            array.push_back(str);
        }
        
        else
        {
            str+= to_string(root->val)+ "->";
        }
        
        traverse(root->left , array, str);
        traverse(root->right, array, str);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> array;
        string str = "";
        
        traverse(root, array , str);
       
        return array;
        
        
    }
};