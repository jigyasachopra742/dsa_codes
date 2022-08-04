#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> m; //first string will contain the sorted string
        //sorted string as key
        //anagram as value 
        //2nd will contain anagrams of that particualr sorted string 
        for(int idx = 0; idx < strs.size(); idx++)
        {
            string s = strs[idx]; //first string //eat
            //sort it
            sort(s.begin(), s.end()); //aet
            m[s].push_back(strs[idx]); //aet => eat, tea, ate
        }
        
        vector<vector<string>> ans;
        
        for(auto x : m) //sab kuch aa gaya //x.first mai sorted string hai
            //x.second mai anagram hai
        {
            auto v = x.second; //stores the anagrams
            ans.push_back(v);

        }
        
        return ans;
        
    }
};