//find max_len here
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int, bool> mp; //first int array, 2nd bool
        
        //first mark all the elements in map as true
        for(int idx = 0 ; idx < nums.size(); idx++)
        {
            mp[nums[idx]] = true;
        }
        
        //now since the question as asked for consecutive seq we will see which element comes in the beginning 
        //if the current element has a prev element already in the map, suppose earlier we marked 4 as true but it hai a prev ele 3 in the map. To maintain the property of consecutive elements, 4 cannot be a starting of the seq. Hence, we will mark 4 as false and 3 will remain as true and it can be a starting number for the seq if it's prev ele is not present
        for(int idx = 0; idx < nums.size(); idx++)
        {
            if(mp.find(nums[idx] - 1) != mp.end())
            {
                mp[nums[idx]] = false; //mark the current ele as false as it's prev ele is present in map, so the curr ele cannot be the starting of the seq
            }
        }
        
        //till now we have marked req ele as true and false 
        //now calculate the max_start_point and max_len at that point in map
        
        int max_start_point = 0;
        int max_len = 0;
        
        int temp_point, temp_len;
        for(int val : nums) //for each loop traversing on nums array
        {
            if(mp[val] == true) //if it is marked as true
            {
                 temp_point = val; //100
                 temp_len = 1; 
            }
            
            //jabtak voh element hamko mil raha hai tab tak temp_len++ karte jao tabhi tou max_len milegi
            while(mp.find(temp_point + temp_len) != mp.end()) //agar uska next ele padha hai
            { 
                temp_len++; //since we want the max_len tou fir jab tak next elements mil rahe hai , increase the temp_len
            }
            
            if(temp_len > max_len) 
            {
                max_start_point = temp_point;
                max_len = temp_len;
            }
            
        }
        
        return max_len;
    }
};