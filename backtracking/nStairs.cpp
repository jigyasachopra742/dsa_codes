#include <bits/stdc++.h>
using namespace std;

int helper(int n)
{
    if(n == 0)
    {
        return 1;
    }

    if(n < 0) 
    {
        return 0;
    }

    return helper(n - 1) + helper(n - 2) + helper(n - 3);
}
int main()
{
    int n = 3;
    cout << helper(n);
}