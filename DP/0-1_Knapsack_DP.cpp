//BOTTOM UP APPROACH
//WE FIRST DO INITIALIZATION
//only table(matrix is used)
//imit recursive calls
//TABULATION METHOD

//WE HAVE TO FIND THE MAXIMUM PROFIT IN THE KNAPSACK SO STORE THE MAXIMUM PROFIT IN A MATRIX
//TAAKI HAMARA STACK OVERFLOW NA HO BAAR BAAR RECURSIVE CALLS KI WAJAH SE
//ISILIYE MATRIX MAI VALUE STORE KARWALETE HAI 1-2 RECURSIVE CALLS KE BAAD
//TAAKI TLE NA AAYE
//WE HAVE TO BUILD AN OPTIMIZED APPROACH

//First row mai always initialization, don't confuse in taking indexes
//Recurive condition ki Base Condition , bottom-up ki initialization mai change ho jaati hai

//1. INITIALIZATION in 1st Row, 1st Column
//First row => n = 0
//First column => W = 0 
//as only these variables are changing in recurive calls

//dono mai se koi bhi ek cheez 0 hui , solve ho hi nahi sakta isiliye 0 kar diya matrix mai

//2. NOW WRITE THE RECURIVE CODE FOR CHOICE DIAGRAM
//function ki jagah write t[n + 1][W + 1]
//t[n][W] basically MAX PROFIT STORE KAR RAHA HAI USKO RETURN KARNA HAI AT THE END

//Item ka weight knapsack ke weight se zzyada hai tou include nahi karenge
//agar kam hai ya knapsack ke weight ke equal hai , then include karenge usko knapsack mai and value decrease karte jaayenge
//size of array har ek case mai kam hoga(logically)
//array ke last block(n - 1)se start karo and n == 0 tak lete jao , smallest valid input base condition
//make a matrix of t[n + 1][W + 1] kyunki 0 se n - 1 tak jaayega, taaki runtime error nah aa jaye ki stack overflow ho gaya
class Solution
{
    //AGAR EK HI ARRAY HOTA HAI THEN CONSIDER THAT ARRAY AS WEIGHT ARRAY NOT VALUE ARRAY
    //BAAKI KI CAPACITY
    
    //Agar include karna hai , nahi karna hai and ek maximum capacity di hai samjh jao knapsack pe based hai

    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int t[n+1][W+1];
       //BOTTOM-UP APPROACH //TABULATION
       for(int i = 0; i < n + 1; i++) //initialization base condition vali approach
       {
           for(int j = 0; j < W + 1; j++)
           {
               if(i == 0 || j == 0)//either on 0th row or on 0th column
               {
                   t[i][j] = 0;
               }
           }
       }
       
       for(int i = 1; i < n + 1; i++)
       {
           for(int j = 1; j < W + 1; j++)
           {
               if(wt[i-1] <= j) //i is dependent on n, j is dependent on W
               {
                   t[i][j] = max(val[i - 1]+t[i - 1][j-wt[i-1]], t[i-1][j]);
               }
               
               else
               {
                   t[i][j] = t[i-1][j]; 
               }
           }
       }
       
       return t[n][W];
       
       
       
       
    }
};