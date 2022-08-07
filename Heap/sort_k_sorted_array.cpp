#include<bits/stdc++.h>
using namespace std;

int sortK(int arr[], int n, int k) 
{
    //6 5 3 2 8 10 9
    priority_queue<int, vector<int>, greater<int>>pq; //min heap
    
    for(int idx = 0; idx < n; idx++)
    {
        pq.push(arr[idx]); //keep on pushing the array elements in pq
    }
    
    while(pq.size() > 0)
    {
        cout << pq.top()<< endl;
        pq.pop();
    }
    
    
    return 0;
//write your code here


}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    int data;
    cin >> data;
    arr[i] = data;
  }
  int k;
  cin >> k;
  sortK(arr, n, k);
  return 0;
}