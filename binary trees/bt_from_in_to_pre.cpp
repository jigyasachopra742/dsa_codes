class Solution {
public:
    //each value of postorder also appears in inorder.
    //inorder: l-root->r
    //postorder: l->r->root
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        map<int, int> mp;
        for(int idx = 0; idx < inorder.size(); idx++)
        {
            mp[inorder[idx]] = idx; //storing the index of the elements of inorder array and we will find them in postorder
        }
        
        TreeNode* root = build(inorder, 0, inorder.size() - 1, mp, postorder, 0, postorder.size() - 1);
        
        return root;
    }
    
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, map<int, int> &mp, vector<int> &postorder, int postStart, int postEnd)
    {
        //EDGE CASES
        if(inStart > inEnd || postStart > postEnd) //that means the arrays are empty
        {
            return NULL; 
        }
        
        TreeNode* root = new TreeNode(postorder[postEnd]); //since last node is ROOT in postorder
        
        int inRoot = mp[root->val]; //storing the initial vale that is root  //this is the index in inRoot because we stored the index in map pf each element
        
        int numLeft = inRoot - inStart;
        
        root->left =  build(inorder, inStart, inRoot - 1, mp, postorder, postStart , postStart + numLeft-1);
        
        root->right = build(inorder, inRoot + 1, inEnd, mp, postorder, postStart + numLeft, postEnd - 1); //postEnd - 1 tak isiliye kyunki last node is our root
        
        return root;
       // for postorder left : postStart, postStart + numLeft  
        //for postorder right: postStart + numLeft + 1, postEnd - 1
        
        
    }
};