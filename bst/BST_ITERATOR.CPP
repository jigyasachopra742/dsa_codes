class BSTIterator {
    
    private: stack<TreeNode* > st;
    
    public:
    //TC : O(1); = O(N) elements/ O(N) calls = O(1)
    //SC : O(H)
     
    BSTIterator(TreeNode* root) //CONSTRUCTOR 
    {
        pushAll(root);
    }
    
    int next() 
    {
        TreeNode* temp = st.top(); //stack ke top pe minimum ele hi tou hofa
        st.pop();
        pushAll(temp->right); //agar right exist karta hai uska extreme left push kardo
        return temp->val; //return that value at top of stack
    }
    
    bool hasNext() 
    {
        return (!st.empty()); //if the stack is non empty we do have elements in stack
    }
    
        void pushAll(TreeNode* root)
        {
            //JABTAK NODE NULL NAHI TAB TAK SAARE EXTREME LEFT PE JAATE HUE PUSH KARTE JAO , YEH INORDER TRAVERSAL HAI
            //ITERATIVE HAMESHA STACK SE HOTA
            //DFS HAMESHA RECURSIVE CALLS SE HOTA
            //BFS HAMESHA LEVEL ORDER WISE MATLAB QUEUE SE HOTA
            for(TreeNode* node = root; node != NULL; node = node->left)
            {
                st.push(node);
            }//push all the lefts, exterme lefts
        }
};
