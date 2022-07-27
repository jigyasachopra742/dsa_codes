class Solution{
    public:
    
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        //SUBSTRING mai jaha discontinuous hua vaha count  = 0 firse nayee tareke se count ko incraese karenge
        int t[n + 1][m + 1];
        
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
        
        int mx = 0;
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(S1[i - 1] == S2[j - 1])
                {
                    t[i][j] = 1 + t[i-1][j-1]; //+1 is for common characters 
                    mx = max(mx, t[i][j]); //maximum common substr find kar rahe
                }
                
                else
                {
                    t[i][j] = 0; //count yaha pe 0 isiliye kardya kyunki hamko continuous chahiye
                    //jaha match nahi hua vaha naye tareke se start karenge ham isiliye vaha
                    //se count = 0 kar diya
                }
            }
        }
        
        return mx;
        
    }
};