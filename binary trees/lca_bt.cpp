class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //if the node matches p or q , return it 
        if(root == NULL || root == p || root == q)
            
        {
            return root;    
        }
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l == NULL)
        {
            return r;
        }
        
        else if(r == NULL)
        {
            return l;
        }
        
        else{
            return root;  //that means agar left and right dono hi kisi value ke saath return ho gaye that means uske beech mai voh value aa gayi hai, return it
        }
    }
};