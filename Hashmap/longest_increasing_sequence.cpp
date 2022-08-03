#include<bits/stdc++.h>
using namespace std;

void longestConsecutive(vector<int>& num) 
{
    unordered_map <int, bool> mp;
    
    for(int idx = 0 ; idx < num.size() ; idx++)
    {
        mp[num[idx]] = true; //seq of ele ki shuruwaat mai true mark kardo
    }
    
    for(int idx = 0 ; idx < num.size(); idx++)
    {
        if(mp.find(num[idx] - 1) != mp.end()) //agar hamko previous element consecutive mai mil jata hai tou current vale ko false kar denge
        {
            mp[num[idx]] = false; //suppose mp.find(9) kya 10 se phele padha hai then mark 10 as false it cannot be starting of sequence
        }
    }
    
    int max_start_point = 0;
    int max_length = 0;
    
    for(int val:num)
    {
        if(mp[val] == true)
        {
            int temp_start_point = val;
            int temp_length = 1;
            
        while(mp.find(temp_start_point + temp_length) != mp.end()) //jabtak mil raha hai map mai tab tak ++ karte jao.
        {
            temp_length++; //1 + 1 = 2 is present temp_len = 2
                            //1 + 2 = 3 is present temp_len = 3
                            //1 + 3 = 4 not present temp_len = 3
        }
        
        if(temp_length > max_length) //3 > 0
        
        {
            max_start_point = temp_start_point; //max_start_point = 1
            max_length = temp_length; // = 3
        
        }
        }
        
    }
    
    for(int idx = 0; idx < max_length; idx++)
    {
        cout << max_start_point + idx << endl;
    }


}

int main()
{
  vector<int>arr;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) 
  {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  
  longestConsecutive(arr);

  return 0;
}