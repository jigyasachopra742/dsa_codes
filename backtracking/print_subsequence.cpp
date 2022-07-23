#include <iostream>
using namespace std;

void printSS(string ques, string ans)
{
    char ch = ques[0];
    if(ques.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    
    
    string s = ques.substr(1);
    printSS(s , ans + ch);
    printSS(s , ans + "");
    
    
}

int main()
{
    string str;
    
    cin >> str;
    
    printSS(str, "");
}