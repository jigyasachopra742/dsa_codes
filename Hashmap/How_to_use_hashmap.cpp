#include<iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string, int> ourmap;

    //1st method for inserting in hashmap
    pair<string, int> p("abc", 1); //either make a pair then insert
    ourmap.insert(p);
    //2nd method of inserting
    ourmap["def"] = 2; //or assign that that key a value in hashmap

    //FINDING AND ACCESSING
    cout << ourmap["abc"] << endl; //will return 1
    cout << ourmap.at("abc") << endl; //will return 1

    cout << ourmap.at("ghi") << endl; //will return an exception error
    cout << "size : " << ourmap.size() << endl; //returns 2 because of abc and def
    cout << ourmap["ghi"] << endl; //will insert in the hashmap and will take a default value 0 in hashmap
    cout << "size : " << ourmap.size() << endl; //will return 3 because ghi has taken a default value 0 in map because we used it as an array

    //CHECKING PRESENCE //count() returns either 0 or 1 depending on whether key is present in hashmap or not
    //each key in hashmap takes only 1 value and that is UNIQUE always
    if(ourmap.count("ghi") > 0){
        cout << "ghi is present" << endl;
    }

    //erase
    ourmap.erase("ghi");
    cout << "size : " << ourmap.size() << endl; //will return 2 now 
    if(ourmap.count("ghi") > 0) //will not work because it is erased from hashmap and it's count is now 0
    {
        cout << "ghi is present" << endl;
    }

}