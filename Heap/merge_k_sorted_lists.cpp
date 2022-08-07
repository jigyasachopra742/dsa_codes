#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

vector<int>mergeKSortedLists(vector<vector<int>>&lists)  //array dubara copy nahi hoga
{
  vector<int> rv;

  priority_queue<int, vector<int>,greater<int>> mp; //min heap
  for(int idx = 0 ; idx < lists.size() ; idx++)
  {
      for(int idx2 = 0 ; idx2 < lists[idx].size(); idx2++)
      {
          mp.push(lists[idx][idx2]); //list of lists
      }

  }

  while(mp.size() > 0)
  {
      rv.push_back(mp.top());
      mp.pop(); 

  }

   
  return rv;
}

int main() {
  int k;
  cin >> k;
  vector<vector<int>>lists;
  for (int i = 0; i < k; i++) {
    vector<int>list;

    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;
      list.push_back(data);
    }

    lists.push_back(list);
  }

  vector<int> mlist = mergeKSortedLists(lists);
  for (int val : mlist) {
    cout << val << " ";
  }
  cout <<endl;
  return 0;
}