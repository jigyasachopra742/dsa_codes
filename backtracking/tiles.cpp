#include <bits/stdc++.h>
using namespace std;

int helper(int n)
{
    if(n <= 3)
    {
        return 1;
    }

    return helper(n - 1) + helper(n - 4);
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;

    cout <<"No of ways to place the tiles : " << helper(n);
}