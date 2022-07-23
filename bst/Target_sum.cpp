#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Node {
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node (int data)
  {
    this->data = data;
  }
};

class Pair {
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

Node* construct(vector<int>& arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {
    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}

bool find(Node* node, int data)
{
    if(node == NULL)
    {
        return false;
    }
    
    if(data < node->data)
    {
        return find(node->left, data);
    }
    
    else if(data > node->data)
    {
        return find(node->right, data);
    }
    
    else //data mil gaya voh jisko search kar rahe
    {
        return true;
    }

}

void travelAndPrint(Node* root, Node* node, int tar) 
{
    if(node == NULL)
    {
        return;
    }
    //INORDER
    travelAndPrint(root, node->left, tar);
    
    int comp = tar - node->data; //to find another number
    
    if(node->data < comp) //agar voh number comp se chhotha hoga tabhi tou search karega
    {
        if(find(root, comp) == true)
        {
            cout << node->data << " " << comp << endl;
        }
    }

    travelAndPrint(root, node->right, tar);
    
  //write your code here

}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);

  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    if (tmp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(tmp);
    }
  }

  int k1;
  cin >> k1;

  Node* root = construct(arr);
  travelAndPrint(root, root, k1);
}