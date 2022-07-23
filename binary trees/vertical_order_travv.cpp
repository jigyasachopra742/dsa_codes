class Solution {
public:
    
    void inOrder(TreeNode* root, int col, int row, map<int, map<int, multiset<int>>> &map) {
        if(root==NULL) return;
        
        inOrder(root->left, col-1, row+1, map);
        
        map[col][row].insert(root->val); //us location pe voh value store ho rahi
        
        inOrder(root->right, col+1, row+1, map);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }
        //set stores unique values
        //multiset can store multiple  elements that can have same value
        
        //Multisets are a type of associative containers similar to the set, with the exception that multiple elements can have the same values.
        map<int, map<int, multiset<int>>> map; //vertical, levels, multiple nodes
        //on every vertical there are going to have multiple levels, for a level we will be having multiple nodes and we need them in a sorted order
        inOrder(root, 0, 0, map);
        
        vector<vector<int>> ans;
        for(auto it:map) //for every vertical, ek particualr vertical pe multiple levels pe traverse kardo
        {
            vector<int> col; //el col banaya
            for(auto p:it.second) //it.second signifies level and multiset 
            {
                col.insert(col.end(), p.second.begin(), p.second.end()); //at every level we are inserting the entire multiset
            }
               
            ans.push_back(col);
        }
        
        return ans;
    }
};