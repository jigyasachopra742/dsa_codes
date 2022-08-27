#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool possible(int A[], int N, int M, int mid)
    {
        int students = 1;
        int sum = 0;
        
        for(int idx = 0; idx < N; idx++)
        {
            sum+= A[idx]; 
            
            if(sum > mid)
            {
                students++; //goes to next student
                sum = A[idx]; //next student ko voh sum allot ho gaya
            }
            
            if(students > M)
            {
                return false;
            }
            
          
        }
        
        return true;
        
        
    }
    int findPages(int A[], int N, int M) 
    {
        if(M > N)
        {
            return -1;
        }
        
        int sum = 0;
        for(int idx = 0 ; idx < N; idx++)
        {
            sum+= A[idx];
        }
        
        //kyunki hamara array ascending order mai sorted hai isliye last value maximum hogi
        //isiliye start ko last value assign hogi
        int start = A[N - 1]; //allot max value to start
        //kyunki 1 book tou sabko allot hogi tou maximum pages hamko allot karne hai
        //tou 1st value ko max value assign kardo aur baakiyon ko sum allot kardo
        int end = sum;
        int res = -1; //will store mid in res
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(possible(A, N, M, mid)) //agar voh vala mid ek feasible answer ho sakta hai
            //usko res mai store karwa do aur minimum karte jao usko
            {
                res = mid;
                end = mid - 1; //as we want minimum number of pages alloted
            }
            
            else
            {
                start = mid + 1; //if there is a need to increase the allocation og pages
            }
            
        }
        
        return res;
        //code here
    }
};