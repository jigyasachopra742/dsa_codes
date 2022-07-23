class Solution {
public:
    
    int max_len = INT_MIN;
    bool check(string s)
    {
        vector<int> v(26, 0);
        for(char ch = 0; ch < s.size(); ch++)
        {
            v[s[ch] - 'a']++; //calculating the frequency
            if(v[s[ch] - 'a'] > 1)
            {
                return false;
            }
        }
        
        return true;
    }
    
    void helper(vector<string>& arr,int idx, string s)
    {
        if(check(s) == false)
        {
            return;
        }
        
        max_len = max(max_len,(int)s.size());
        //s,.size() unsigned long de raha tha and max mai 2 parameters same type ke hone chahiye isiliye usmei typecast kar siya
        if(idx == arr.size())
        {
            return;
        }
        
        helper(arr, idx + 1, s + arr[idx]); //ek baar daal
        helper(arr, idx + 1, s); //ek baar nahi daala
        
    }
    
    
    int maxLength(vector<string>& arr) 
    {
        helper(arr,0, "");
        return max_len;
        
        
    }
};