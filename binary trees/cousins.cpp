class Solution 
{
public:
    
    int x_depth , y_depth;
    TreeNode* x_p;
    TreeNode* y_p;
    
    void set_parent_depth(TreeNode* root, int x, int y ,TreeNode* parent , int height)
    {
        if(root == NULL)
        {
            return;
        }
        
        set_parent_depth(root->left , x , y , root ,height + 1);
        set_parent_depth(root->right , x , y , root , height + 1 );
        
        //RETURN KARNE KE BAAD ROOT->VAL 4 BAN GAYI
        if(root->val == x) //at leaf node 4 == 4
        {
            x_p = parent; //x_p = 4
            x_depth = height; //x_depth = 2
            
        }
        
         if(root->val == y) //at leaf node 3 == 3
         {
            y_p = parent; //y_p = 3
            y_depth = height; //y_depth = 2
            
         }
        
    }
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if(root == NULL)
        {
            return false;
        }
        
        set_parent_depth(root , x , y , NULL, 0);
        
        if(x_depth == y_depth && x_p != y_p) //2 = 2 && 4 != 3 (TRUE)
        {
            return true;
        }
        return false;
    }
};