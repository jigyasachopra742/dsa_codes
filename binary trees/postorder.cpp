
class Solution {
public:
    
    vector<int> array;//initially empty array
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root == NULL)
        {
            return array; //return a khali array if the root is NULL
        }
        
        //POSTORDER: LEFT->RIGHT->ROOT
        postorderTraversal(root->left); //left call
        postorderTraversal(root->right); //right call
        array.push_back(root->val); //push the root in array
        
        return array;
        
    }
};