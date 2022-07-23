// Return the root of the modified tree after removing all the half nodes.
Node *RemoveHalfNodes(Node *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    
    if(root->left == NULL && root->right == NULL)
    {
        return root;
    }
    
    if(root->left == NULL && root->right != NULL)
    {
        return root->right;
    }
    
    else if(root->left != NULL && root->right == NULL)
    {
        return root->left;
    }
    
    return root;
    
   
    
   //add code here.
}