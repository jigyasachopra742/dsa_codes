#include <iostream>
using namespace std;

class node
{
    public :
        int data; //elements
        node* next;
};

class linked_list
{
    public:
        node* head, *tail;
        int size = 0; //initial size of node is 0

public:
    linked_list() //constructor
    {
        head = NULL;
        tail = NULL;
    }

    void addLast(int n)
    {
        node* temp = new node(); //we have fisrt created the node
        temp->data = n; //put the value in the data part of temp node
        temp->next = NULL; //initially set the address part of temp node as NULL
        
        if(size == 0) //if ll is empty
        {
            head = tail = temp; //kyunnki 1 hi node hai
        }
        
        else
        {
            tail->next = temp; //purani tail se new node temp ko jodh diya pointing at temp
            tail = temp; //now temp is the new tail node as we want to insert node at last
        }
        
        size++; //har case mai size badhega
        // Write your code here


    }
    void display() {
        for (node* tmp = head; tmp != NULL; tmp = tmp->next) {
        cout << tmp->data << " ";
        }

    }


  void testList() {
    for (node* temp = head; temp != NULL; temp = temp->next) {
      cout << temp->data << endl;
    }
    cout << size << endl;

    if (size > 0) {
      cout << tail->data << endl;
    }
  }
};


int main() {


  string str;
  linked_list l;
  while (true) {
    getline(cin, str);
    if (str[0] == 'q') {
      break;
    }
    if (str[0] == 'a') {
      string ss = str.substr(8, 2);
      int n = stoi(ss);
      l.addLast( n);

    }

  }

  l.testList();
  return 0;

}