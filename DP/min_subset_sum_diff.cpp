#include<bits/stdc++.h> 
using namespace std; 
//last row baatyegi answer kyunki usmei saare elements hai
//jo values true return kar rahi unki vector v mai store kar wa liya

class Solution {
public:
    //[1, 2, 7] = {1,2} - {7} = abs(3 - 7) = 4 can be a minimum possible answer
    //phele ek range nikal lo
    //us range ki help se subset sum array mai jo ele given hai unki help se 
    //determine karo ki S1 / S2 ki kya value hogi
    //use subset sum to find the value of S1
    //s1 + s2 = S = RANGE
    //s2 = range - s1 //ek hi partition karna hai dusra partition apne aap ho jaayega
    //min(s2 - s1) = min(range - s1 - s1) = min(range - 2 * s1)
    //ab s1 find karne ke liye ham range lenge kyunki s1 ke liye possible candidates usi range mai lie karenge //s1 cannot be greater than range/2
    //suppose range is 10 , s1 ke liye range/2 take that is 5 rak possible 1,2,3
    //s1 = 1 => range - 2s1 = 10 - 2 = 8
    //s1 = 2 => range - 2s1 = 10 - 4 = 6
    //s1 = 3 => range - 2s1 = 10 - 6 = 4 (min) 
    //also 4 is possible in subset [1, 2, 7] = {1,2} - {7} = abs(3 - 7) = 4
    vector<int> subsetsum(vector<int>& nums, int n, int range)
    {
        //apne lo ek array given hai [1,2,7] ismei min possible diff is 4
        //so find sum 4 in the subset using subset sum
        //is array mai aisa subset exist karta hai jiska sum 4 hai
        vector<int> ans;
        bool t[n + 1][range + 1];
        
         for(int i = 0 ; i < n + 1 ; i++){
	        for(int j = 0 ; j < range + 1 ; j++)
            {
	             
                if(i == 0)
	                t[i][j] = false; //ek particular
	            
	            if(j == 0)
	                t[i][j] = true; //sum can be 0
	        }
	    }
    
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < range + 1; j++)
            {
                if(nums[i - 1] <= j)
                {
                    t[i][j] = (t[i-1][j-nums[i-1]]) || (t[i-1][j]); //either including the value or not
                }
                
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        //we have to minimize (range - 2*s1)
    
        for(int i = 0 ; i < n +1; i++) //s1
        {
            for(int j = 0 ; j <= range/2; j++)
            {
                if(t[i][j] == 1)
                {
                    ans.push_back(j); //sum(S1) push_back karna hai
                }
            }
            
        }
        
        return ans;
       
    }
    
    
    int minimumDifference(vector<int>& nums) 
    {
        int range = 0;
        int n = nums.size();
        
        for(int idx = 0; idx < n; idx++)
        {
            range+= nums[idx]; //calcualting the maximum possible sum(range in which )
        }
        
        vector<int> v = subsetsum(nums, n, range);  //for finding possible candidates of S1
        //v = [1,2,3] for array = [1,2,7]
        int mn = INT_MAX;
        
        for(int idx = 0; idx < v.size(); idx++)
        {
            mn = min(mn, abs(range-(2*v[idx]))); //possible candidates are in vector v(True vale)
        }
        
        return mn;
       
    }
};