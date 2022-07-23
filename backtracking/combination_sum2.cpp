class Solution 
{
public:
    
    vector<vector<int>> ans; //2d array jismei overall result store ho raha hai
    vector<int> arr; //1d array push karne vala
    
    void getCombination(vector<int>&candidates,vector<int>& arr, int idx, int target)
    {
        if(target == 0) //that means we have found the element
        {
            ans.push_back(arr);
            return;
        }
        
        if(target < 0)
        {
            return;
        }
        
        for(int idx1 = idx; idx1 < candidates.size() && target >= candidates[idx1]; idx1++)
        {
            if(idx1 == idx || candidates[idx1] != candidates[idx1 - 1]) //the second condition is for duplicate elements
            {
                arr.push_back(candidates[idx1]);
                getCombination(candidates, arr , idx1 + 1 , target - candidates[idx1]);
                arr.pop_back();
            } //if target - candidates[idx1] == 0 that means we have found the target
        }
    }
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)     
    {
        sort(candidates.begin(), candidates.end());
        getCombination(candidates, arr, 0, target);
        return ans;
    }
};