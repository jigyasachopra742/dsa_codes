#include <iostream>
using namespace std;
class node {
public:
  int val;
  node* next;

  node(int data)
  {
    val = data;
    next = NULL;
  }


};
class LinkedList {
public:
  node* head = nullptr;
  node* tail = nullptr;
  int size_ = 0;

  void insert_at_tail(int val) {
    if (head == NULL) {
      node* newnode = new node(val);
      
      head = newnode;

    }
    else {
      node* newnode = new node(val);
      node* temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newnode;
    }

  }

  void print () { //HOW TO DISPLAY THE NODES
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
    delete temp; //TEMP KO HEAD PE POINT KARWADO THEN DELETE TEMP

  }

  int size() {
    int cnt = 0;
    node* temp = head;
    while (temp != NULL) { //HOW TO COUNT THE NUMBER OF NODES IN LINKED LIST
      temp = temp->next;
      cnt++;
    }
    return cnt;
  }

  void getFirst() {
    cout << head->val << endl; //GETTING THE HEAD NODE
  }

  void getLast() {
    node* temp = head;
    while (temp->next != NULL) { //GETTING THE TAIL NODE
      temp = temp->next;
    }
    cout << temp->val << endl; //JAB WHILE LOOP END PE REACH KAR GAYA THEN PRINT THE LAST NODE 
  }

  node* getAt(int p) { //GETTING THE NODE AT AN INDEX
    int cnt = 0;
    node* temp = head;
    while (cnt < p) {
      cnt++;
      temp = temp->next;
    }
    cout << temp->val << endl;
    return temp;
  }

  void addFirst(int val) { //ADDING THE VALUE AT FIRST NODE
    node* newnode = new node(val);
    if (head == NULL) {
      head = newnode;
    }
    else {
      newnode ->next = head;
      head = newnode;
    }

  }

  void addAt(int pos, int data) 
  { //ADDING THE VALUE AT AN INDEX
         if(pos == 0)
         {
            addFirst(data);
         }
         
         else if(pos == size())
        {
            insert_at_tail(data);       
        }
        
        else
        {
         node* temp = head;//head has been attached to temp node
         int count = 0;
         while(count < pos - 1)
         {
            count++;
            temp = temp->next;
         }
         
         node* newNode = new node(data);
         newNode->next = temp->next;
         temp->next = newNode;
            
        }
        
     
     
  }

  void removeLast() //REMOVING THE VALUE FROM LAST
  {
    if(size() == 0)
    {
        cout << "List is empty" << endl;
    }
    
    else if(size() == 1)
    {
        head = NULL;
        tail = NULL;
        size_= 0;
    }
    
    else
    {
        node* temp = head;
        
        for(int idx = 0; idx < size() - 2; idx++) //kyunki hamei last vali node delete karni hai isiliye size - 2 tak leke jaa rahe
        {
            temp = temp->next;
        }
        //JAB BAHAR AA YEGA TOU 2ND LAST PE POINT KAR RAHA HOGA
        tail = temp; //matlab ki 2nd last element pe tail ko point karwadu
        tail->next = NULL; //fir tail ke next ko NULL SET KARDO
       
        //TOU FIR VOH DELETE HO JAYEGA
    }
    
    
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
      l1.addFirst(data);
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
    else if (s == "removeLast") {
      if (l1.head != NULL) {
        l1.removeLast();
      }
      else {
        cout << "List is empty" << endl;
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