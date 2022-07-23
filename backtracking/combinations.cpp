class Solution 
{
public:
    
    void helper(int n, int k, vector<int> &temp, vector<vector<int>> &ans, int idx)
    {
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i <= n; i++) //i = 1; 1 <= 4
        {
            temp.push_back(i); //temp push(idx) /
            helper(n, k, temp, ans, i + 1); //helper(n,k,temp,ans, 2)
            temp.pop_back();
            //we have done pop back to create space so that new elements can come
         
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(n, k, temp, ans, 1); //4, 2, temp, ans, 1 
        return ans;
    }
};