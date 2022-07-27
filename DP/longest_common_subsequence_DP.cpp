class Solution {
public:
    
    int lcs(string text1, string text2, int n, int m)
    {
        //BOTTOM UP APPROACH(TABULATION)
       //TABLE SIRF UNHI KE LIYE BANTA HAI JO VALUES CHANGE HO RAHI HOTI HAI
        int t[n + 1][m  + 1];
        //initialization //in terms of i and j
        
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
                if(text1[i - 1] == text2[j - 1]) //AGAR LAST KA CHARACTER DONO KA MATCH KAR RAHA HAI //TOU FIR REDUCE BOTH OF THEM
                {
                    t[i][j] = 1 + t[i-1][j-1]; //+1 is for common characters  1 + t[n - 1][m - 1]
                } //AGAR COMMON HAI TABHI TOU LENGTH MAI  ++ KARENGE
                
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]); //AGAR NAHI MATCH KARTE TOU WE HAVE 2 CHOICES 1st array ka pura consider karlo 2nd vale ka half consider karlo and vice-versa
                }
            } //max(t[n - 1][m], t[n][m - 1])
        }
        
        return t[n][m];
    }
    //ismei +1 isiliye nahi kiya kyunki common nahi hai
    
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        //If there is no common subsequence, return 0. (AS PER THE QUESTION)
        int n = text1.size();
        int m = text2.size();
        
         //think of the smallest valid input it is always 0
         //if the size of any one of the str is 0, return 0
        
        //always in recursion start from last and go to smallest VALID INPUT
        
        //SMALL KARNE KA TRY KARO, ALWAYS LOOK FROM LAST
        
        //sara last pe depend kar raha hai ki char lena hai ki nahi
        
        //APPROACH: agar last element dono strings ka match ho jata hai tou n-1, m-1 ke liye vapis se recursive call kardo and piche piche jaate jayo, jase hi valid milta usko store karwalo and last char fir haatate bhi jao kyunki match and use ho gaya voh
        
        //suppose agar last vala char match nahi hote dono strings ke then we have 2 choices: ya fir tou ham pheli string ko pura lele and 2nd string ka last vala remove karde ya fir 1st vali string ka last remove karde and 2nd string ko pura lele aisa isiliye kyunki agar by chance 1st str ka last char agar 2nd str ke last char se match nahi hua kya pata 1st str ka 2nd last character 2nd str ke last char se match ho raha ho and vice-versa isiliye yeh approach lag gaayi incase agar last char match nahi hote
        
        int ans = lcs(text1, text2, n, m);
        return ans;
       
        
    }
};