class Solution 
{
public:
    
    vector<string>ans;
    
    void getpare(string str , int open , int close)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(str);
            return;
        }
        
        if(open > 0)
        {
            getpare(str + "(" , open - 1 ,close); //jab tak open hai tab tak open milega
        }
        
        if(close > open) //jaise hi open ka count kam hua close se matlab ab usse close karna padega
        {
            getpare(str + ")" , open , close - 1);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        getpare("" , n , n);
        return ans;
    }
};