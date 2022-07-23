class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root == NULL)return NULL;
        
        Node* curr = root;
        while(curr->left != NULL)
        {
            Node* temp = curr; //why becuase we have to move to next level after each iteration and we have to start from left till NULL and curr will be pointing to NULL hence we stored it in temp
            while(curr != NULL)
            {
                curr->left->next = curr->right; //2 ke left node pe 4 is pointing to 5
                curr->right->next = curr->next==NULL ? NULL : curr->next->left;
                //5 ke next pe store 6 instead of NULL
                curr = curr->next; //move to 3 node
                
            }
            curr = temp->left; //moves to next level that is on 4
            
        }
        
        
        
        return root;
    }
};