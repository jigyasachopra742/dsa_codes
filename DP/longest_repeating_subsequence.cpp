//https://leetcode.com/problems/longest-subsequence-repeated-k-times/(DO THIS QUES IT IS IMP ON LEETCODE)

class Solution {
	public:
		int LongestRepeatingSubsequence(string str)
		{
		    string str2 = str;
		    
		    int n = str.size();
		    int m = str2.size();
		    
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
		    //here the approach is that agar dono strings mai same index pe aa raha tou don't
		    //include them, agar criss-cross ho raha then only and only including common ones
		    for(int i = 1; i < n + 1; i++)
		    {
		        for(int j = 1; j < m + 1; j++)
		        {
		           if(str[i - 1] == str2[j - 1] && i != j)
		           {
		               t[i][j] = 1 + t[i - 1][j - 1];
		           }
		           
		           else
		           {
		               t[i][j] = max(t[i-1][j], t[i][j - 1]);
		           }
		        }
		    }
		    
		    return t[n][m];

		}

};