class Solution 
{
public:
    
    vector<vector<int>>answer;
    
    vector<int> temp;
    
    void get_subsets(vector<int>& nums , int idx ,vector<int> temp)
    {
        if(idx == nums.size())
        {
            answer.push_back(temp);
            return; //[] 
        }
        
        get_subsets(nums , idx + 1 ,temp);
        
        temp.push_back(nums[idx]); //[] 
        
        get_subsets(nums , idx + 1 , temp); //[] , [1], [2], [3]
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        get_subsets(nums , 0 , temp);
        
        return answer;
        
    }
};