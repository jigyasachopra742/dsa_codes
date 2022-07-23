class Solution{
  public:
  
  //har ek vertical line pe jao sum add karte jao
  //remember don't use horizontal lines , vertical lines pe sum calculate karna hai
    void inorder(Node* root, int x, map<int, int> &mp)
    {
        if(root == NULL) return;
        inorder(root->left, x - 1, mp); //while moving left
        mp[x]+= root->data; //we have inserted the nodes at a vertical line 
        inorder(root->right, x + 1,  mp); //while moving right
    }
    
    vector <int> verticalSum(Node *root) 
    {
        vector<int> ans;
        int sum = 0;
        if(root == NULL)return {};
        
        map<int, int> mp; //vertical lines, values at those lines
        
        inorder(root, 0, mp);
        
        for(auto itr : mp)
        {
            
            ans.push_back(itr.second);
        }
        
        return ans;
        // add code here.
    }
};

//{ Driver Code Starts.
int main() 
{
    
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector <int> res = obj.verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
}
// } Driver Code Ends