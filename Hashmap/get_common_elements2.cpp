#include<bits/stdc++.h>
using namespace std;

int main() 
{
  unordered_map <int, int> mp; //both the arrays a1 and a2 have type int
  int n1, n2;
  cin >> n1;
  int arr1[n1];

  for (int i = 0; i < n1; i++) 
  {
    cin >> arr1[i];
    mp[arr1[i]]++; //initally 0 hai lekin usi waqt ++ karne ki wajah se 1 ho gayi frequency
  }
  
  cin >> n2;
  int arr2[n2];
  for (int i = 0; i < n2; i++) 
  {
    cin >> arr2[i];
    
    if(mp[arr2[i]] > 0) //agar voh element arr2 ka map mai present hai
    {
        cout << arr2[i] << endl; //tou fir print it
        mp[arr2[i]]--; //then reduce the frequency of that element in map by 1
    }
    
  }

}