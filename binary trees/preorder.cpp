class Solution {
public:
    
    /* To summarize, at a node whether we have to move left or right is determined whether the node has a left subtree. If it doesn’t we move to the right. If there is a left subtree then we see its rightmost child. If the rightmost child is pointing to NULL, we move the current node to its left. If the rightmost child is already pointing towards the current node, we remove that link and move to the right of the current node. We will stop the execution when the current points to null and we have traversed the whole tree.

*/
    //LEFT NODE EXISTS KARE NA KARE RIGHT NODE ZAROOR EXIST KARNI CHAHIYE
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> preorder;
        TreeNode* curr = root;
        
        while(curr != NULL)
        {
            if(curr->left == NULL) //edge case
            {
                preorder.push_back(curr->val); //push the root node
                curr = curr->right; //simply move to right subtree
            }
            
            else //if the left subtree exists
            {
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr) //jab tak rightmost node nahi aa jaati tab tak deeply jaate jao and jab tak prev ka right is not pointing to itself
                {
                    prev = prev->right; //go as much right as you can and connect the thread with the root node that is curr;
                }
                
                if(prev->right == NULL) //suppose we have reached the rightmost node
                {
                    prev->right = curr; //connect the thread
                    preorder.push_back(curr->val); //for preorder push the root node
                    curr = curr->left; //point to the left subtree now traverse that tree                
                }
                
                //2nd case will be what if the the node is already pointing to itself
                //then remove the thread and move aage
                else
                {
                    prev->right = NULL; //usko null karwado
                    curr = curr->right; //then traverse the right subtree
                }
                
            }
        }
        
        return preorder;
        
    }
};