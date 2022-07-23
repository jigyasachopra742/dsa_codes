class Solution 
{
public:
    
    vector<int> temp;
    vector<vector<int>>answer;
    void get_subsets(vector<int>& nums , int idx , vector<int> temp)
    {
        
        
        answer.push_back(temp);   
        
        
       for(int ind = idx ; ind < nums.size(); ind++)
       {
           if(ind != idx && nums[ind] == nums[ind - 1]) continue;
       
            temp.push_back(nums[ind]);
            get_subsets(nums, ind + 1, temp);
            temp.pop_back();

       }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end()); //sorting is for duplicates ko ek saath  karne ke liye
        
        get_subsets(nums , 0 , temp); 
        
        return answer;
    }
};