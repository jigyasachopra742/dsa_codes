class Solution 
{
public:
    vector<string> helper(string digits)
    {
        string keypad[10] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
        if(digits.size() == 0) //BASE CASE
        {
            return {""};
        }
        
        char ch = digits[0];
        string ros = digits.substr(1);
        
        vector<string> rres = helper(ros); //ros being passed as remaining digits
        vector<string> mres; 
        string codesforch = keypad[ch - '0']; //storing those characters jispe traverse karenge
        
        for(int idx = 0; idx < codesforch.size(); idx++) //pqrs
        {
            char chcode = codesforch[idx]; //1-1 charcter pr traverse karenge //p
            for(string rstr : rres) //rstr phele p ke saath, fir q, fir r,fir s
            {
               mres.push_back(chcode + rstr);
            }
            
        }
        
        return mres;
    }
    
    vector<string> letterCombinations(string digits) 
    {   
        vector<string> ans;
        if(digits.size() == 0)
        {
            return {};
        }
        
        ans = helper(digits);
        return ans;
       
    }
};