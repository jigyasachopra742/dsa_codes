//SIMILAR TO PRINTING LCS
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        //THE APPROACH HERE IS SIMILAR TO LCS ONLY
        //YAHA PE SARE CHARACTERS INCLUDE KARNE HAI OF BOTH THE STRINGS 
        //SO WORST CASE IS DONO STRINGS KO JODH DO BUT VOH HAMEI NAHI KARNA 
        //SO THE BEST CASE IS LCS MINUS KARDO WE WILL GET THE REQUIRED STRING LENGTH AND AGAR PRINT KARWANA HAI THEN LCS SE PHELE MATRIX DP[N][M] MAI VALUES STORE KARO AND THEN EK KHALI STRING BANAO USMEI LAST BOTTOM RIGHT CORNER SE MATCHING KARO CHARACTERS KI AGAR MATCH HOTE HAI THEN INCLUDE AGAR NAHI HOTE TAB BHI INCLUDE KARO KYUNKI YEH SUPERSEQUENCE KA QUESTION HAI 
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
            while(i > 0 && j > 0)
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
                    s1.push_back(str1[i-1]); //ELEMENT SAARE LELETE
            //COMMON 1 BAAR LIYA BUT SAARE CHARACTERS LIKHE
                    i--;
                }
                
                else
                {
                    s1.push_back(str2[j - 1]);//ELEMENT SAARE LELETE
            //COMMON 1 BAAR LIYA BUT SAARE CHARACTERS LIKHE
                    j--;
                }
                
                
            }
        
        while(i > 0) //is case mai agar j 0 ho gaya lekin i nahi hua tab bhi ham uske characters push karenge
        {
            s1.push_back(str1[i - 1]); //JO COMMON NAHI HAI USKO INCLUDE KARNA HAI IN SCS
          
            i--;
        }
        
        while(j > 0) //is case mai agar i 0 ho gaya lekin i nahi hua tab bhi ham uske characters push karenge
        {
            s1.push_back(str2[j - 1]);
            j--;
        }
          
        
        reverse(s1.begin(), s1.end());
        return s1;
        
    }
};