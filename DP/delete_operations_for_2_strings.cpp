class Solution {
public:
    
    int tabulation(string word1, string word2, int n, int m)
    {
       
        //THE QUESTION IS JUST THE REPLICA OF LONHEST COMMON SUBSEQUENCE WE ONLY HAVE TO RETURN THE COMMON SUBSEQUENCE LENGTH
        int t[n + 1][m + 1];
        
        for(int i = 0 ; i < n + 1; i++) //initialization
        {
            for(int j = 0; j < m + 1; j++)
            {
                if(i == 0 || j == 0) //agar string 1 mai 0 hai tou ans 0
                                    //agar string 2 mai 0 hai tou bhi 0 ans kuch common hi nahi hoga
                {
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(word1[i - 1] == word2[j - 1]) //common agar hai //at 0th character kyunki 1 se start kiya I guess
                {
                    t[i][j] = 1 + t[i - 1][j - 1]; //+1 is for common
                }
                
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        
        return t[n][m];
            
    }
    
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();
        
        int ans = tabulation(word1, word2, n , m); //stroes the count of LCS
        
        //minimum number of steps required to make word1 and word2 the same.
        return n + m - 2*ans;// total length of both the strings - 2 * common
        //min number of deletion : n.size() - LCS
        //min number of insertion : m.size() - LCS 
       
        //Total steps : n.size() - LCS + m.size() - LCS : n.size() + m.size() -2*LCS
        
        
    }
};