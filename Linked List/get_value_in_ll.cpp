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

  void insert_at_tail(int val) 
  {
    if (head == NULL) 
    {
      node* newnode = new node;
      newnode->val = val;
      newnode->next = NULL;
      head = newnode;

    }
    
    else 
    {
      node* newnode = new node;
      newnode->val = val;
      newnode->next = NULL;
      node* temp = head;
      while (temp->next != NULL) 
      {
        temp = temp->next;
      }
      
      temp->next = newnode;
    }

  }

  void print () 
  {
    node* temp = head;
    if (head == NULL) 
    {
      cout << "0" << endl;
      return;
    }
    while (temp != NULL) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  void deletion_at_head() 
  {
    if (head == NULL) return;
    node* temp = head;
    head = head->next;
    delete temp;

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

  void getFirst()  //FOR THE FIRST NODE, PRINT HEAD
  {
    
    cout << head->val << endl; //1ST NODE VALUE PRINT 
   
  }

  void getLast()  //FOR THE LAST NODE , TRAVERSE TILL THE END OF THE LIST AND PRINT THE LAST NODE
  {
      node* temp = head; //start from head
      while(temp->next != NULL)
      {
          temp = temp->next;
      }
    
      cout << temp->val << endl; //JAISE HI LAST PE PAUNCH JAYEGA WHILE LOOP LAST VALI NODE PRINT HO JAYEGI
  }
   
  

  node* getAt(int p) //p is that index at which we have to find 
  {
      int count = 0;
      node*temp = head; //pointing at head //kabhi bhi head ke saath nahi khelna always pint head to a new node varaible
      
      while(count < p)
      {
          count++; //COUNT TAB TAK BADEGA JAB TAK COUNT P TAK NAHI PAUNCH JAATA, P IS THE INDEX AT WHICH WE HAVE TO PRINT THE NODE
          temp = temp->next; //TRAVERSING THE LIST
      }
      
      cout << temp->val << endl; //when count exceedes or becomes equal to p
      return temp;
    //write your code here
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
    else if (s == "getFirst") {
      if (l1.head != NULL) {
        l1.getFirst();
      } else {
        cout << "List is empty" << endl;
      }
    }
    else if (s == "getLast") {
      if (l1.head != NULL) {
        l1.getLast();
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
    cin >> s;
  }
}