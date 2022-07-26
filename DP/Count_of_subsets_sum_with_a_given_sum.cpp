int count_subsets(vector<int>& nums, int sum1, int target)
    {
        int n = nums.size();
        int t[n + 1][sum1 + 1]; //we have to find that sum
        
        for(int j = 0; j < sum1 + 1; j++)
        {
            t[0][j] = 0;  //false
        }
        
        for(int i = 0; i < n + 1; i++)
        {
            t[i][0] = 1; //true
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 0; j < sum1 + 1; j++)
            {
                if(nums[i - 1] <= j)
                {
                    t[i][j] = (t[i-1][j - nums[i-1]] + t[i-1][j]); //include + exclude
                }
                
                else
                {
                    t[i][j] = (t[i-1][j]); //exclusing if greater
                }
            }
        }
        
        return t[n][sum1];
    }
    