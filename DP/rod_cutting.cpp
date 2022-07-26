class Solution{
  public:
   
    int cutRod(int price[], int n) 
    {
        vector<int> length_arr;
        for(int idx = 1; idx <= n; idx++) //1 to N
        {
            length_arr.push_back(idx); //length to be cut
        }
        
        int length_size = length_arr.size();
        
        int t[length_size+1][n + 1];
        
        for(int i = 0; i < length_size + 1; i++)
        {
            for(int j = 0; j < n + 1; j++)
            {
                if(i == 0 || j == 0) //agar length of arr ya fir price array mai 0 hua tou 0 ans
                {
                    t[i][j]=0;
                }
            }
        }
         // n is the total length , jitni length ka cut karte jaayenge usko n se minus karte jaayenge
         //and price ki value add karte jaayenge
        
        for(int i = 1; i < length_size + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(length_arr[i-1] <= j) //can be included
                {
                    t[i][j]= max(price[i-1] + t[i][j - length_arr[i-1]], t[i-1][j]);
                }
                
                else
                {
                    t[i][j] = t[i - 1][j]; //cannot be included
                }
            }
        }
        
        return t[length_size][n];
       
    }
};