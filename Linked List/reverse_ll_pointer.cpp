#include <iostream>
using namespace std;
class node {
public:
  int val;
  node* next;


};
class LinkedList {
public:
  node* head = nullptr;
  node* tail = nullptr;
  int size_ = 0;

  void insert_at_tail(int val) {
    if (head == NULL) {
      node* newnode = new node;
      newnode->val = val;
      newnode->next = NULL;
      head = newnode;

    }
    else {
      node* newnode = new node;
      newnode->val = val;
      newnode->next = NULL;
      node* temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newnode;
    }

  }
  void insertion_at_head(int val) {
    node* newnode = new node;
    newnode->val = val;
    newnode->next = NULL;
    if (head == NULL) {
      head = newnode;
    }
    else {
      newnode ->next = head;
      head = newnode;
    }

  }
  void print () {
    node* temp = head;
    if (head == NULL) {
      cout << "0" << endl;
      return;
    }
    while (temp != NULL) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  void deletion_at_head() {
    if (head == NULL) return;
    node* temp = head;
    head = head->next;
    delete temp;

  }
  void deletion_at_tail() {
    if (head == NULL) return;
    node* previous = NULL;
    node* temp = head;
    while (temp->next != NULL) {
      previous = temp;
      temp = temp->next;
    }
    previous->next = NULL;
    delete temp;
  }


  void last() {
    node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    cout << temp->val << endl;
  }
  int size() {
    int cnt = 0;
    node* temp = head;
    while (temp != NULL) {
      temp = temp->next;
      cnt++;
    }
    return cnt;
  }
  void first() {
    cout << head->val << endl;
  }

  node* getAt(int p) {
    int cnt = 0;
    node* temp = head;
    while (cnt < p) {
      cnt++;
      temp = temp->next;
    }
    cout << temp->val << endl;
    return temp;
  }

  void addAt(int pos, int data) {
    if (pos == 0) {
      insertion_at_head(data);
      return;
    }
    node* newnode = new node;
    newnode->val = data;
    int cnt = 0;
    node* temp = head;
    while (cnt < pos - 1) {
      cnt++;
      temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;


  }

  void removeAt(int pos) {
    if (pos == 0) {
      deletion_at_head();
      return;
    }
    int cnt = 0;
    node* temp = head;
    while (cnt < pos - 1) {
      cnt++;
      temp = temp->next;
    }
    temp->next = temp->next->next;
  }

  void reverse_di() {
    int left = 0;
    int right = size() - 1;
    while (left < right) {
      node* templ = getAt( left);
      node* tempr = getAt( right);

      int temp = templ->val;
      templ->val = tempr->val;
      tempr->val = temp;
      left++;
      right--;
    }
  }
  
  void reverse_pi() 
  {
    if(size() <= 1)
    {
        //head = NULL;
        //tail = NULL;
        return; //khali return ho jayega kyunki 1 hi element padha hai
    }
    
    node* t = head; //making the tail node
    while(t->next != NULL)
    {
        t = t->next;
    }
    
    tail = t;

    node* prev = NULL; //prev ko NULL pe isiliye karwaya, taaki usko curr pe point karwa sake
    node* curr = head; //first node ki taraf point karwa rahe hai
    
    while(curr != NULL)
    {
        node* tem = curr->next; //store it so that we can move aage
        curr->next = prev; //curr ka jo next hai uska aage se next element se connection break karke prev pe connect karwa diya
        prev = curr; //prev node curr node ban gayi
        curr = tem; //curr node next node ban gayi matlab aage badh gayi
    }
    
    //HERE WE ARE SWAPPING THE HEAD NODE WITH TAIL NODE
    node* p = head;
    head = tail;
    tail = p;
    
    
    // write your code here
  }
};
int main() {
  LinkedList l1;
  string s;
  cin >> s;
  while (s != "quit") {
    if (s == "addLast") {
      int data;
      cin >> data;
      l1.insert_at_tail(data);
    }
    else if (s == "addFirst") {
      int data;
      cin >> data;
      l1.insertion_at_head(data);
    }
    else if (s == "getFirst") {
      if (l1.head != NULL) {
        l1.first();
      } else {
        cout << "List is empty" << endl;
      }
    }
    else if (s == "getLast") {
      if (l1.head != NULL) {
        l1.last();
      }
      else
      {
        cout << "List is empty";
      }

    }
    else if (s == "removeFirst") {
      if (l1.head != NULL) {
        l1.deletion_at_head();
      }
      else {
        cout << "List is empty" << endl;
      }
    }

    else if (s == "getAt") {
      if (l1.head != NULL) {
        int i;
        cin >> i;
        if (i >= l1.size()) {
          cout << "Invalid arguments" << endl;
        }
        else {
          l1.getAt(i);
        }
      }
      else
      {
        cout << "List is empty";
      }

    }
    else if (s == "display") {
      if (l1.head != NULL) {
        l1.print();
      }
      else {
        cout << endl;
      }
    }
    else if (s == "size") {
      if (l1.head != NULL) {
        cout << l1.size() << endl;
      }
    }
    else if (s == "addAt") {
      int val, i;
      cin >> i >> val;
      if (i > l1.size()) {
        cout << "Invalid arguments" << endl;
      }
      else {
        l1.addAt(i, val);
      }
    }
    else if (s == "removeLast") {
      if (l1.head != NULL) {
        l1.deletion_at_tail();
      }
      else {
        cout << "List is empty" << endl;
      }
    }
    else if (s == "removeAt") {
      if (l1.head != NULL) {
        int i;
        cin >> i;
        if (i > l1.size()) {
          cout << "Invalid arguments" << endl;
        }
        else {
          l1.removeAt(i);
        }
      }
      else {
        cout << "List is empty" << endl;
      }
    } else if (s == "reverseDI") {
      if (l1.head != NULL) {
        l1.reverse_di();
      }
      else {
        cout << "List is empty" << endl;
      }
    }
    else if (s == "reversePI") {
      if (l1.head != NULL) {
        l1.reverse_pi();
      }
      else {
        cout << "List is empty" << endl;
      }

    }
    cin >> s;
  }

}