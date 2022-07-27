class Solution 
{
    //ANOTHER APPROACH: Find LCS common in both the strings
    //if LCS length is equal to the length of string 1 , then it is true
    //that means choti string puri ki puri badhi vali mai aa rahi
    //otherwise it is false

public:
    bool isSubsequence(string s, string t) 
    {
        int idx_s = 0;
        int idx_ts = 0;
        
        
        while(idx_ts < t.size()) //1
        {
            if(s[idx_s] == t[idx_ts]) //choti vali string puri ki puri badhi vali mai aari
                
            {
                idx_s++; //1
            }
            
            idx_ts++;
        }
        
        if(idx_s == s.size())
        {
            return true;
        }
        
        return false;
    }
};