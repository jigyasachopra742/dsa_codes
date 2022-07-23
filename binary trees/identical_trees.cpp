class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL && q == NULL) //dono hi empty hai means dono hi same hue , isiliye return true
        {
            return true;
        }
        
        if(p == NULL && q != NULL) //ek null hai , ek nahi hai dono different hai
        {
            return false; //isiliye return false
        }
        
        if(p != NULL && q == NULL) //same as above
        {
            return false;
        }//EDGE CASES
        
        //MAKE THE CALLS FOR LEFT SUBTREE AND RIGHT SUBTREE
        
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);
        
        if(l == false || r == false)
        {
            return false;
        }
        
        if(p->val == q->val)
        {
            return true;
        }
        
        return false;
        
    }
};