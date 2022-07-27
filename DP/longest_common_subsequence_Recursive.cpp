class Solution {
public:
    //GAVE TLE
    int lcs(string text1, string text2, int n, int m)
    {
        if(n == 0 || m == 0)
        {
            return 0;
        }
        
        
        if(text1[n - 1] == text2[m - 1])
        {
            //+1 is only for common characters
            return 1 + lcs(text1, text2, n - 1, m - 1); //agar same hai tou add kardo +1 and baaki ki bachi hui string mai so jo bhi aayega usko bhi
        }//KYUNKI THERE CAN BE COMMON AMONG THEM
        
        else
            return max(lcs(text1, text2, n, m - 1), lcs(text1, text2, n - 1, m));
    }//KYUNKI THERE CAN BE COMMON AMONG THEM SHAYAD LAST 2ND LAST SE MATCH HOTA HO
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