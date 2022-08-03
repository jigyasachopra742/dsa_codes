#include <bits/stdc++.h>
using namespace std;


int main()
{
    int max = 0;
    char max_char;
    string str;
    cin >> str;
    
    unordered_map <char, int> ourmap;
    
    for(int idx = 0 ; idx < str.size() ; idx++)
    {
        ourmap[str[idx]]++; //apne jo str[idx] pe jo character hai voh apne map mai corresponding value increment ho jayegi
        
        //agar array ke through kar rahe ho tou usse ek default value mil jayegi that is  0
    }
    
    unordered_map <char, int>:: iterator it = ourmap.begin();
    while(it != ourmap.end())
    {
        if(max < it->second)
        {
            max = it->second;
            max_char = it->first;
        }
        
        it++;
    }
    
    cout << max_char << endl;
}