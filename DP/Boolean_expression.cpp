class Solution{
public:

 
    int t[201][201][2];
    int solve(string &S, int idx1, int idx2, bool state)
    {
        if(idx1 > idx2)
        {
            return 0;
        }
        
         if(t[idx1][idx2][state]!=-1) return t[idx1][idx2][state];  //MEMORIZATION
        
        if(idx1 == idx2)
        {
            return((state == 1 && S[idx1] == 'T') || (state == 0 && S[idx1] == 'F'));
             //DONO MAI SE KOI BHI TRUE HUA TOU RETURN TRUE
        }
        
        
        int ans = 0;
        for(int k = idx1 + 1; k <= idx2 - 1; k = k + 2) //first i is always an expression 
        //second i is an operator isiliye idx1 + 1 kiya hai and k = k + 2 isiliye kyunki har ek expression ke baad hai 
        //operator
        {
            int lt = solve(S, idx1, k - 1, 1); //kabhi left expression evaluate hoke will return true
            int lf = solve(S, idx1, k - 1, 0); //kabhi left expression evaluate hoke will return false
            int rt = solve(S, k + 1, idx2, 1); //kabhi right expression evaluate hoke will return true
            int rf = solve(S, k + 1, idx2, 0); //kabhi right expression evaluate hoke will return false
            
            if(S[k]=='&')
            {
                if(state) ans+=lt*rt; //KITNE TRUE STATES HAI
                else ans+= lf*rf+lf*rt+lt*rf; //KITNE FALSE STATES HAI
            }
            else if(S[k]=='|')
            {
                if(state) ans+= lt*rf+lf*rt+ lt*rt; //KITNE TRUE STATES HAI
                else ans+= lf*rf; //KITNE FALSE STATES HAI
            }
            else if(S[k]=='^')
            {
                if(state) ans+= lt*rf+lf*rt; //KITNE TRUE STATES HAI
                else ans+= lt*rt+lf*rf; //KITNE FALSE STATES HAI
            } 
            
        }
        

        return t[idx1][idx2][state] = ans % 1003; //returns number of possible ways modulo 1003.
        
    }
    int countWays(int N, string S)
    {
        memset(t, -1, sizeof(t));
        return solve(S, 0, N-1, true);
        // code here
    }
};