class Solution {
public:
    //APPRAOCH: EK 2d vector banao usmei hamara final answer aayega and ek 1d vector nums jismei ham voh elements push karenge jinke frequency , fre array mai 1 baar mark hue then unko marke karke call lagao next ele pe jao the jaise nums.size() == temp.size() ho jata hai then pop_back() and then unmark vapis aate hue
    vector<vector<int>> solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int freq[])
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return ans;
        }
        
        
        for(int idx = 0; idx < nums.size(); idx++) //1
        {
            if(!freq[idx]) //agar marked nahi hai element
            {
                temp.push_back(nums[idx]); //jo jo unique hai push in temp 1D vector
                freq[idx] = 1; //mark true that element taaki voh duabara nah aaye
                
                solve(nums, temp, ans, freq); //call lagado for next element
                //vapis aate hue unmark karo
                temp.pop_back(); //creating space for new elements
                freq[idx] = 0; //unmark it
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        int n = nums.size();
        int freq[n]; //initialize freq with 0
        /*for(int idx = 0; idx < nums.size(); idx++)
        {
            freq[idx] = 0;
        }*/
        
        memset(freq, 0, sizeof(freq));
        
        return solve(nums, temp, ans, freq);
        
    }
};