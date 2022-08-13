//a : AGGTAB // GTAB
//b : GXTXAYB //GTAB

//common LCS : GTAB

//a + b - LCS = AGGTAB + GXTXAYB(GTAB) - GTAB
//STRING : AGGXTXAYB = 9 return it //1 hi baar aana chahiye 
//worst case of SCS : a + b
//best case : take LCS
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //THIS IS A PART OF LCS ONLY YAHA PE SAARE STRINGS KO INCLUDE KARNA HAI
        //YAHA PE WORST CASE CAN BE KI SAARI STRINGS KO INCLUDE KARLO M + N
        //BUT YAHA PE DONO STRINGS MAI KUCH COMMON  AA RAHA HAI USKO MINUS KARKE WE CAN GET THE 
        //BEST RESULT
        int t[m + 1][n + 1];
        for(int i = 0; i < m + 1; i++)
        {
            for(int j = 0; j < n + 1; j++)
            {
                if(i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(X[i - 1] == Y[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        //FIND LCS FIRST, USKO FIR MINUS KARDO 
        //2 GTAB KO KYU MERGE KAR RAHE 
        //MINUS KARDO
        //COMMON KO 1 HI BAAR USE KARDO(GTAB IN string a)
        return m + n - t[m][n]; //LENGTH OF SCS
    }
};
 