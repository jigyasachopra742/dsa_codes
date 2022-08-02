#include<iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    
    unordered_map<string, int> mp;
    mp["abc"] = 1;
    mp["abc1"] = 2;
    mp["abc2"] = 3;
    mp["abc3"] = 4;
    mp["abc4"] = 5;
    mp["abc5"] = 6;

    unordered_map<string, int>:: iterator itr = mp.begin();
    while(itr != mp.end())
    {
        cout << "key : " << itr->first << "value : " << itr->second << endl;
        itr++;
    }
}

//prints in an unordered way because it is an unordered map
//no particular order
//sari values ko access kar paa rahe iterate kar kar ke
//yahi agar ordered_map hota tou sorted order mai print hota

//vectors aloso conatin iterators similar to map