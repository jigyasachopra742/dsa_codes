//LPS(a) : LCS(a, reverseof(a));
//LPS mai ek hi string given hai
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());//kyunki ek string missing hai usko derive karlo then lcs nikal ko and jo LCS aa raha that should be palindromic and longest among all palindromic LCS'S
        
        int n = s.size();
        
        int t[n + 1][n + 1];
        
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0 || j == 0)
                {
                   t[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(s[i - 1] == s2[j - 1]) //if the last character matches
                {
                    t[i][j] = 1 + t[i - 1][j - 1]; //dono mai minus ho gaye kyunki dono match kar gaye ab peeche [eeche jao and match karte jao
                }
                
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]); //ya fir tou s string ko half lelo and s2 ko pura ya fir s ko pura , s2 ko half kyunki shayad there is a possiblity ki 
                    //peehe vala aage se match ho jaaye ya fir aage vala peeche se
                }
            }
        }
        
        return t[n][n];
        
    }
};