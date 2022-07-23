class Solution {
public:
    
    void traverse2(TreeNode* root, vector<int> &inorder, int &idx)
    {
        if(root == NULL)return;
        
        
        traverse2(root->left, inorder, idx);
        root->val = inorder[idx++]; //][1,2,3]
        traverse2(root->right, inorder, idx);
        
    }
    void traverse(TreeNode* root, vector<int> &inorder)
    {
        if(root == NULL)return;
        
        traverse(root->left, inorder);
        inorder.push_back(root->val); //gives[3,2,1]
        traverse(root->right, inorder);
        
    }
    
    void recoverTree(TreeNode* root) 
    {
        vector<int> inorder;
        traverse(root, inorder); //traverse the tree to get an inorder array
        //we get [3,1,2] according to previous tree given so to get a sorted BST we will first sort the array that we have recieved
        sort(inorder.begin(), inorder.end()); //we get a sorted array [1,2,3]
        
        int idx = 0; //keep an index so that it traverses thriugh an array
        traverse2(root, inorder, idx);
      
        
    }
};