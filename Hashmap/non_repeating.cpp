class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        unordered_map<int, int> mp;
        
        for(int idx = 0; idx < n; idx++)
        {
            mp[arr[idx]]++; //frequency map
        }
        
//here we can use itr.second as well to denote the frequency of each element
        for(int idx = 0; idx < n; idx++)
        {
            //here mp is the freq map which is only storing the frequencies of all the elements
            if(mp[arr[idx]] == 1) //if freq of that ele in map is 1
            {
                return arr[idx];
            }
        }
        
        
        return 0;
        // Complete the function
        
    } 
  
};