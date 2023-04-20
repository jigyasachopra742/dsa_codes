#include <bits/stdc++.h>
using namespace std;

//there should not be consecutive 1's 
int helper(int n, int ld)
{
    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        if(ld == 0)
        {
            return 2;
        }

        else if(ld == 1)
        {
            return 1;
        }
    }

    if(ld == 0)
    {
        return helper(n - 1 , 1) + helper(n  - 1, 0);
    }

    else if(ld == 1)
    {
        return helper(n - 1, 0);
    }
}


int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;

    cout << helper(n, 0);
}