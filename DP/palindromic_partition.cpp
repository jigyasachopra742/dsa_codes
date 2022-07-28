class Solution {
public:
    
    bool isPalindrome(string &s)
    {
        int start = 0;
        int end = s.size() - 1;
        while(start <= end)
        {
            if(s[start++] != s[end--])
            {
                return false; //first checking whether all the cases are palindrome or not
            }
        }
        
        return true;
    }
    
    void helper(string &s,  vector<vector<string>> &result, vector<string> &ans)
    {
        if(s.size() == 0)
        {
            result.push_back(ans);
            return;
        }
        
        //FOR PARTIONING USE LOOP
        for(int i = 0; i < s.size(); i++)
        {
            string leftpart = s.substr(0, i + 1);
            if(isPalindrome(leftpart))
            {
                ans.push_back(leftpart);
                helper(s.substr(i + 1), result, ans);
                ans.pop_back(); //FOR DIFFERENT CASES 
                //BACKTRACK KARTE KARTE EMPTY STRING AA JAYEGI THEN TEMP KO OUTPUT ARRAY MAI
                //DAAL DO USKE BAAD NEXT ITERATION KE LIYE CHALO
            }
        }
       
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        vector<string> ans;
        
        helper(s, result, ans); //void type
        
        return result;
    } 
};