class Solution 
{
public:
    
    vector <vector <int>>ans;
    vector<int> arr;
    void getCombination(vector<int>& candidates, vector<int>& arr, int idx , int sum , int target)
    {
        if(sum > target)
        {
            return;
        }
    
        if(sum == target)
        {
             ans.push_back(arr);
             return;
        }   
        
        for(int idx1 = idx ; idx1 < candidates.size() ; idx1++)
        {
            if(sum + candidates[idx1] <= target)
            {
                arr.push_back(candidates[idx1]);
                getCombination(candidates,arr,idx1,sum+ candidates[idx1], target);
                arr.pop_back();
            }
            
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        getCombination(candidates , arr , 0 , 0 , target);
        return ans;
    }
};