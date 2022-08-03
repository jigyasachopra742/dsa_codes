#include<unordered_set>
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        //GET COMMON ELEMENTS PEPCODING LEVEL 1
        unordered_set<int> s;
        vector<int> array;
        
        for(int idx = 0; idx < nums1.size(); idx++)
        {
            s.insert(nums1[idx]); //frequency map
        }
        
        for(int val : nums2)
        { //[1,2,2,1] ==
            if(s.find(val) != s.end()) //[2,2]
            {
                array.push_back(val); //2 is pushed in array
                s.erase(val);  //set se erase 2
            }
        }
        
        return array;
    }
};