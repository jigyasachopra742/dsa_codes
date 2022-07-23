#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

Node* construct(vector<int>& arr) 
{
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) 
  {

    if (st.top().second == 1) 
    {
      st.top().second++;
      if (arr[idx] != -1) 
      {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else 
      {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) 
    {
      st.top().second++;
      if (arr[idx] != -1) 
      {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else 
      
      {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    
    else 
    {
      st.pop();
    }

  }
  return root;
}


int min(Node* node) 
{
    if(node->left == NULL)
    {
        return node->data;
    }
    
   return min(node->left);
    
}

int max(Node* node) 
{
    if(node->right == NULL) //by chance agar right subtree mai null hai tou root ko dekhenge 
    {
        return node->data;
    }
    
   return max(node->right);
    
}

int sum(Node* node) 
{
    if(node == NULL)
    {
        return 0;
    }
    
  
    int sum_nodel = sum(node->left);
    int sum_noder = sum(node->right);
    
    return sum_nodel + sum_noder + node->data;

}


int size(Node* node) 
{
    if(node == NULL)
    {
        return 0;
    }
    
    
    int countl = size(node->left);
    int countr = size(node->right);
    int count = countl + countr + 1; // 1 is for node (root) ka size
    
    return count;
}


bool find(Node* node, int data) 
{
    if(node == NULL)
    {
        return 0;
    }
    
    if(node->data == data)
    {
        return true;
    }
    
    bool left = find(node->left , data);
    bool right = find(node->right , data);
    
    if(left == true || right == true)
    {
        return true;
    }
    
}


int main() 
{
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) 
  {
    string x;
    cin >> x;
    if (x == "n") 
    {
      arr[i] = -1;

    }
    
    else 
    {
      arr[i] = stoi(x);
    }
  }
  
  int data;
  cin >> data;
  Node* root = construct(arr);
  cout << size(root) << "
" << sum (root) << "
" << max(root) << "
" << min(root) <<  "
";
  if (find(root, data)) 
  {
    cout << "true" << endl;
  }
  
  else 
  {
    cout << "false" << endl;
  }
}