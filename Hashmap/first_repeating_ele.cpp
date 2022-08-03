#include<unordered_map>
using namespace std;

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) 
    {
        unordered_map<int, int> mp;
        
        for(int idx = 0; idx < n; idx++)
        {
            mp[arr[idx]]++; //frequency map
        }
        
//here we can use itr.second as well to denote the frequency of each element
        for(int idx = 0; idx < n; idx++)
        {
            if(mp[arr[idx]] > 1)  //mp[4] > 1 => 3 > 1 yes 
            {
                return idx + 1; //1 based indexing
            }
        }
        
        return -1; //if all elements are unique return -1 as mentioned in ques 
        // code here
    }
};