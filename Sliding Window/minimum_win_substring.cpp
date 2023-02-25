//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(s.size() < t.size())
        {
            return "";
        }
        
        unordered_map<char, int> mp;
        int i = 0, j = 0; //start and end index of window
        int min_len = INT_MAX; //minimum len of string
        string ans = "";
        
        for(int idx = 0; idx < t.size(); idx++)
        {
            mp[t[idx]]++; //storing the string t and charcters count in map mp
        }
        
        int count = mp.size(); //count is equal to the unique characters in map
        
        while(j < s.size())
        {
               if(mp.find(s[j]) != mp.end()) //agar voh end tak nahi jaata matlab voh character map mai mil gaya
                {
                    mp[s[j]]--; //us particular character ka count map mai decrement kardo
                    if(mp[s[j]] == 0)    //decrease count if val is 0
                    {
                        count--; //if the count of that character in map becomes 0 that means it all consumed hence we will decrease the count of the map as that character count in map has become 0
                    }
                   
                   //j++;
                }
        
                if(count == 0) //possible string mil gayi ,sliding window hit ho gayi
                {
                    if(min_len > j - i + 1) //when sliding window hits find the solu
                    {
                        ans = s.substr(i, j - i + 1);
                        min_len = j - i + 1;
                    }

                    while(i <= j && count == 0) //when there are extra characters in window
                    {
                        if(mp.find(s[i]) != mp.end()) //matlab char mil gaya
                        {
                            mp[s[i]]++;  //extra characters agar aa gaye then 1 kardo occurrence

                            if(mp[s[i]] == 1)
                            {
                               if(min_len > j - i + 1) //when sliding window hits find the solu                 
                               {
                                    ans = s.substr(i, j - i + 1);
                                    min_len = j - i + 1;
                               } 
                                
                                count++; //matlab ki voh char dubara map mai aa gaya and window se nikal gaya hence count 1 se increase kar diya, string ab eligible nahi hai, jab count = 0 hoga tabhi eligible string hogi, count = 0 ka matlab hai sare characters ka count map mai 0 ho gaya that means all the characters are consumed but jab koi extra character aa jata hai tab uska count++ kar diya 0 se 1 ho gaya then count bhi 1 ho gaya kyunki voh character aa gaya

                            }
                        }

                        i++; //jabtak answer mil raha hai tab tak increment i kyunki shayad aage ek aur chota answer mil jaye  
                    }
                    
                }
            
            j++; //altogether j++ kar diya 


        }
        
        if(min_len == INT_MAX)
            return "";
        
        return ans;
    }
};