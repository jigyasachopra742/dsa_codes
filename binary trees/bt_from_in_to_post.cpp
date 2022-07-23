class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        //Each value of inorder also appears in preorder.
        map<int, int> mp; //gives the answer in sorted manner
        
        for(int idx = 0; idx < inorder.size(); idx++)
        {
            mp[inorder[idx]] = idx; //the particular value is stored at a particular index 
        } //and then we will search for the root in preorder array
        
        TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        
        return root;
        
    }
    
    TreeNode* build(vector<int> &preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &mp)
    {
        //EDGE CASE
        if(preStart > preEnd || inStart > inEnd) //that means arrays are empty 
        {//preStart should always start with 0 index it cannot be greater than end index
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]); //the initail value, root is stored
        
        //where is that root lying in inorder array
        int inRoot = mp[root->val]; //we will search for that root value in inorder array and make it the root for inorder array and do the partition , usse phele ke saare left subtree , uske baad ke saare
        //right subtree
        
        int numleft = inRoot - inStart; //for applying inorder in the remaining block
        
        root->left =  build(preorder, preStart + 1, preStart + numleft, inorder, inStart, inRoot - 1, mp); //ab root ke left pe node lagayenge
        
         root->right =  build(preorder, preStart + numleft + 1, preEnd, inorder, inRoot + 1, inEnd, mp); //ab root ke right pe node lagayenge
        //for attaching right subtree we will traverse till end
        return root;
        
    }
};