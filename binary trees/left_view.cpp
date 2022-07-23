
 //TIME COMPLEXITY: O(n);
 //SPACE COMPLEXITY: O(H); //level wise jaa rahe

//Function to return a list containing elements of left view of the binary tree.

void leftrecursion(Node *root, int level, vector<int> &res) //2, 1,[1,3] //2 par ho level 1 hi hai
{
    if(root == NULL) //not null
    {
        return;                  // 1
                                //  /  \
                                  3    2
    }
    
    if(level == res.size()) //level = 1 , res.size()= 2 res.push_back(1,3)
    //res = [1, 3]
    {
        res.push_back(root->data); //LEVEL ORDER KI TARAH 
    }
    
    leftrecursion(root->left, level + 1, res); //NULL, 1, [1]
    leftrecursion(root->right, level + 1, res); //NULL , return to 1 call 2 
}

//return [1,3]


vector<int> leftView(Node *root)
{//preorder traversal
    vector<int> res;
    leftrecursion(root, 0, res);
    return res;
  
   //last node is the left view of every level
   
   // Your code here
}
