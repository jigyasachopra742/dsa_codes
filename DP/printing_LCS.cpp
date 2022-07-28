class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        //THE APPROACH HERE IS SIMILAR TO LCS ONLY

           int n = str1.size();
		   int m = str2.size();
		   
		   int dp[n + 1][m + 1];
		   
		   for(int i = 0; i < n + 1; i++)
           {
                for(int j = 0; j < m + 1; j++)
                {
                    if(i == 0 || j == 0)
                    {
                        dp[i][j] = 0;
                    }
                }
            }
        //PHELE DONO STRINGS MAI SE COMMON CHARACTERS LE LIYE USHING LCS APPROACH
            for(int i = 1; i < n + 1; i++) //shuru se shuruwaat karo and then store maximum length in matrix
            {
                for(int j = 1; j < m + 1; j++)
                {
                    if(str1[i - 1] == str2[j - 1])
                    {
                        dp[i][j] = 1 + dp[i-1][j-1]; //+1 is for common characters 
                    }
                    
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            
            //Till now we have stored the max length values in the t matrix now will print the longest subsequence
            
            string s1 = "";
            
            int i = n, j = m;
            while(i > 0 && j > 0) //dono mai se koi bhi empty hua tou LCS kaha se niklega 
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    s1.push_back(str1[i - 1]);
                    i--;
                    j--;
            
                }
                
                //AGAR MATCH NAHI HAI TOU MAXIMUM DEKHO WITH THE HELP OF VALUES STORED IN t[n][m]
                
                else if(dp[i-1][j] > dp[i][j -1])
                {
                    i--;
                }
                
                else
                {
                    j--;
                }
                
                
            }
        
        reverse(s1.begin(), s1.end());
        return s1;
        
    }
};