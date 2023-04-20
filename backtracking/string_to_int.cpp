#include <bits/stdc++.h>
using namespace std;

int f(char *arr, int n)
{
    if(n == 0)
    {
        return 0;
    }

    int digit = arr[n - 1] - '0'; //converting to int
    return f(arr, n - 1) * 10 + digit;
}
int main()
{
    char arr[100] = "4329";
    int n = strlen(arr);
    cout << f(arr, n);

}