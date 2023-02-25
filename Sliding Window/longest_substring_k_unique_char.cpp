//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        unordered_map<char, int> mp;
        int i = 0, j = 0; //start and end index of window
        int max_len = -1; //no possible substring, print -1
        
        while(j < s.size())
        {
            mp[s[j]]++; //pushing the characters of the string in map mp
            //mp will push the charcters with some count that is if it is a unique char then it will 
            //push the char in mp with count 1 otherwise if the character is already present in map mp
            //then it will increment the count = count + 1
            //HashMap is a collection to store (key,value) pairs and According to the documentation of HashMap the keys are always unique.
//If you add a key which already exists(collision) in the hashmap, the old value will be replaced.
            if(mp.size() < k) //here the condition is mp.size() because map mp consists of unique characters only
            {
                j++;
            }
            
            else if(mp.size() == k)
            {
                max_len = max(max_len, j - i + 1);
                j++;
            }
            
            else if(mp.size() > k) //by chance ek aur unique char aa jata hai map mai tab 
            {
                while(mp.size() > k)
                {
                    mp[s[i]]--; //jo phele hi characters aa chuke hai map mai unka count 1 se decrease kar diya
                    
                    if(mp[s[i]] == 0) //agar us char ki occurence 0 ho gayi map mai tou that character dosen't exist anymore in the map
                    {
                        mp.erase(s[i]); //so that the size of the map mp reduces
                    }
                    
                    i++; //start index of window
                }
                
                j++; //end index of window 
            }
        }
        
        return max_len;
    }
};