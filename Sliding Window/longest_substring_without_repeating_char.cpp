//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> mp; //map for storing unique characters
        int i = 0, j = 0;
        int max_len = 0;
        
        while(j < s.size())
        {
            mp[s[j]]++;
            
            if(mp.size() == j - i + 1) //that means all the characters in the window are unique
            {
                max_len = max(max_len, j - i + 1);
                j++;
            }
            
            else if(mp.size() < j - i + 1) //that means now there is no unique character in map, instead one of the character has repeated that's why mp size is smaller than the window size
            {
                while(mp.size() < j - i + 1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) //if the count of that repeating character becomes 0 in map, then remove it 
                    {
                        mp.erase(s[i]);//erasing the repeating element from map mp
                    }
                    i++;
                }    
                j++;
            }
        }
        
        return max_len;
    }
};