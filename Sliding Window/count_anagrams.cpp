#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int search(string pat, string txt) 
	{
	   unordered_map<char , int> mp;
	   int ans = 0;
	   for(int idx = 0; idx < pat.size(); idx++)
	   {
	       mp[pat[idx]]++; //mp mai push ho gaye saare elements
	   }
	   
	   int k = pat.size();
	   int i = 0, j = 0, count = mp.size();
	 
	   while(j < txt.size())
	   {
	        //calculation part
	      if(mp.find(txt[j]) != mp.end()) //matlab duplicate mil gaya
	      {
	          mp[txt[j]]--; //reduce the count of that specific character in map
	          
	          if(mp[txt[j]] == 0)
    	      {
    	          count--; //count becomes 0 that means all the characters are matched in pattern
    	      }
	      }
	      
	      //not hit the window part
	      if(j - i + 1 < k)
	      {
	          j++;
	      }
	      
	      //hit the window part
	      else if(j - i + 1 == k)
	      {
	          if(count == 0)
	          {
	              ans++;
	          }
	          
	          //ham end tak tabtak jaate hai jabtak duplicate nahi mil jata 
	          //agar nahi milta voh character in map matlab voh end tak jaayega dhundne
	          //agar mil jata hai tou end tak nahi jayega and count++ kar dega
	          
	           if (mp.find(txt[i]) != mp.end()) //As long as find does not return mp.end(), we know that the key is present in the map.
	           {
                   mp[txt[i]]++;
                  
                   if (mp[txt[i]] == 1) //that means that character has again come
                   {
                       count++;
                   }
	           }
	           
	           i++;
	           j++;
	         
	      }
	       
	   }
	   
	   return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends