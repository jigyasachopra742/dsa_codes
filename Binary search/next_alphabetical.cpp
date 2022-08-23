#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        // that means we have to find ceil
        int left = 0;
        int right = letters.size() - 1;
        int n = letters.size();
        char ans;
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            
            if(letters[mid] > target) // a possible candidate tou usko kam banao        
            {
                right = mid - 1; //shift right towards left taaki usko peeche peeche kar sake
               
            }
            
            else
            {
                 left = mid + 1; //shift aage
                
            }
        }
        
        return letters[left % letters.size()];
    }
};
