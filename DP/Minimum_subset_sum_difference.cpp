
 // } Driver Code Ends
class Solution{
//similar to equal partition sum
//SABSE PHELE TOU ISMEI RANGE NIKALENGE S1 = 0
//S2 = SUM OF ALL THE ELEMENTS
//RANGE = S2 - S1
//AB ISMEI KON KON SE ELEMENTS AAYENGE
//US LINE MAI SE HAMKO VOH CANDIDATE CHOOSE KARNE HAI JO KI 
//Range : sigma(array elements) summation
//S1 - S2 = minimize
//s1 nikal lo
//s2 = range - S1
//S2 - S1 = (Range - S1 - S1)min = (Range - 2S1)min
//Range - 2S1 always an absolute value
//S1 hamara Range/2 tak jaayega, Range/2 ke aage S2



  public:
  
    vector<int> subsetSum(int arr[], int n, int range)
    {
        bool t[n + 1][range + 1];
        vector<int> ans;
         for(int i=0;i<n+1;i++){
	        for(int j=0;j<range+1;j++){
	            if(i==0)
	            t[i][j]=false;
	            
	            if(j==0)
	            t[i][j]=true; //sum can be 0
	        }
	    }
        
        //phele tou possible subsets nikal lo jo us sum ke barabar ho
        //kon kon si values pe S1 exist karega
        //ham basically last row mai true or false check kar rahe hai 
        //ki size 3 mai aisa konsa subset hai jiska sum 10 hai 
        //0,1,2,3,4,5,6,7,8,9
        //jaha jaha true return ho raha hai usko vector <int> ans mai store karlo(1,2,3) halfway tak
        //store the last row(halfway) for s1 because S1 ko kam rakhna hai!!
        //push the halfway subsets in vector<int> ans

        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < range + 1; j++)
            {
                if(arr[i - 1] <= j)
                {
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j]; //US SUM KE LIYE ELIGIBLE SUBSETS
                }
                
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        //uske baad range/2 tak jaayenge and check karenge kya us subset mai voh values fit hai
        //and then push in array
        //YAHA S1 KE LIYE KAR RAHE
        //SUBSET MAI KON KON SI VALUES PE SUM EXIST KAREGA
        for(int i = 0; i < n + 1; i++)
        {
            for(int j = 0; j <= range/2; j++)
            {
                if(t[i][j] == 1) //VALUES (SUM1) AT LOCATION
                {
                    ans.push_back(j); //pushing the possibe sum (S1); //(1,2,3) halfway tak
                }
            }
        } //PUSH THE ELIGIBLE SUMS (S1)
        
        return ans;
        
        
    }
    
	int minDifference(int arr[], int n)  
	{ 
	    int range = 0;
	    for(int idx = 0; idx < n; idx++)
	    {
	        range+= arr[idx];
	    }
	    //EK ARRAY MAI AISA SUBSET EXIST KARTA HAI KI NAHI
	    vector<int> v = subsetSum(arr, n, range); //this vector will return the possible answer
	    int mn = INT_MAX;
	    for(int idx =0 ; idx < v.size(); idx++) //traverse on (1,2,3)
	    {
	        mn = min(mn, abs(range-2*v[idx])); //will iterate on every element of subset
            //array mai jisbhi element pe minimum aayega usko return kardo

            //range - 2s1 = range - s1 - s1 = s2 - s1 => minimum differnce
 	    }
	    
	    return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends