class Solution 
{
public:
    //ISMEI HAMKO SORTED ARRAY SE BST CONSTRUCT KARNA HAI THAT'S IT 
    TreeNode* helper(vector<int> &nums, int lo, int hi)
    {
        if(lo > hi)return NULL;
        
        int mid = lo + (hi - lo) / 2; //overflow
        
        TreeNode* root = new TreeNode(nums[mid]); //root pe mid lagana hai
        
        root->left = helper(nums, lo, mid - 1);
        root->right = helper(nums, mid + 1, hi);
        
        return root;
       
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size() == 0)
        {
            return NULL;
        }
        
        return helper(nums, 0, nums.size() - 1);
      
    }
};