class Solution {
public:
    
    int lps(string s, string s2, int n, int m)
    {
       int t[n + 1][m + 1];
         
        for(int i = 0; i < n + 1; i++)
        {
            for(int j = 0; j < m + 1; j++)
            {
                if(i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(s[i - 1] == s2[j - 1])
                {
                    t[i][j] = 1 + t[i-1][j-1]; //+1 is for common characters 
                }
                
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        
        return t[n][m];
    
    }
    
    int minInsertions(string s) 
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        
        int n = s.size();
        int m = s2.size();
        
        int ans = lps(s, s2, n , m); //longest palindromic substring
        
        int insertion = n - ans;
        return insertion;
    }
};