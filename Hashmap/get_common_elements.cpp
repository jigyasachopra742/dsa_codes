#include <iostream>
#include <unordered_map>
using namespace std;
//Map contains the values of arr1
//if map contains the value which are there in arr2 as well the cout << arr[2] and erase
int main() 
{
  unordered_map <int, int> mp; //both the arrays a1 and a2 have type int
  int n1, n2;
  cin >> n1;
  int arr1[n1];

  for (int i = 0; i < n1; i++) 
  {
    cin >> arr1[i];
    
    mp[arr1[i]]++; //this map stores the frequency of each number in map
    //number of occurences
  }
  
  cin >> n2;
  int arr2[n2];
  
  for (int i = 0; i < n2; i++) 
  {
    cin >> arr2[i];
    
    if(mp.count(arr2[i]) > 0) //if that number in arr2[i] has occured already in map
    {
       cout << arr2[i] << endl;  //then print it
       mp.erase(arr2[i]); //erasing prev value taaki map mai aage na mile
    }
    
  }
}