/* To summarize, at a node whether we have to move left or right is determined whether the node has a left subtree. If it doesn’t we move to the right. If there is a left subtree then we see its rightmost child. If the rightmost child is pointing to NULL, we move the current node to its left. If the rightmost child is already pointing towards the current node, we remove that link and move to the right of the current node. We will stop the execution when the current points to null and we have traversed the whole tree.

*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        //THREADED BINARY TREE O(1) Space complexity(this is main), o(n) time complexity 
        
        vector<int> inorder;
        TreeNode* curr = root;
        
        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            //but if the left subtree exists then we will connect the last node that is the rightmost node of the left subtree to the root node (means go the left, go to the rightmost guy)
            
            else
            {
                TreeNode* prev = curr->left; //prev node is pointing to left subtree
                //go as right as you can
                //if the right exists and right is not pointing to itself then make a thread
                while(prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;//go as right as you can
                }
                
                if(prev->right == NULL) //agar leaf node nikla rightmost mai
                {
                    prev->right = curr; //making the thread , connecting the rightmost to root node
                    curr = curr->left; //start the traversal in left subtree
                }
                
                else{ //prev->right pointing to itself that means prev->right = curr
                    prev->right = NULL;
                    inorder.push_back(curr->val); //because it is a root now
                    curr = curr->right; //now traversing on right
                    
                }
            }
        }
        
        return inorder;
        
    }
};