vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root == NULL)return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(q.size() != 0)
    {
        Node* curr = q.front();
        q.pop();
        
        while(curr)
        {
           if(curr->left)
           {
               q.push(curr->left); //push the left nodes in queue q and if right node becomees null
               //pop them out of queue push them in ans and there children that are on right
           }
           
           ans.push_back(curr->data); //push only th right nodes becuase while traversing diagonally 
           //we are going in the right direction //phele root data ko push kiya fir right direction mai gaye
           curr = curr->right; 
        }
    }
   // your code here
}