#include <bits/stdc++.h>
using namespace std;

void ReplacePI(char *arr, int index)
{
    if(arr[index] == '\0' && arr[index+1] == '\0')
    {
        return;
    }
    if(arr[index] == 'p' && arr[index + 1] == 'i')
    {
        int j = index + 2; //kyunki phele 2 characters PI HAI isiliye 2 chars aage chalo
        while(arr[j] != '\0')
        {
            j++;
        }
 //j is on the last char
        while(j >= index + 2) //vaha se kiya start
        {
            arr[j + 2] = arr[j];
            j--;
        }

        arr[index] = '3';
        arr[index + 1] = '.';
        arr[index + 2] = '1';
        arr[index + 3] = '4';

        ReplacePI(arr, index + 4); //changes in the original array
    }

      else{
            ReplacePI(arr, index+1);
        }
}
int main()
{
    char arr[100] = "piaapiabhe";
    int n = strlen(arr);
    cout << "Before replacing PI:" << arr << endl;
    ReplacePI(arr, 0);
    cout << "After replacing PI:" << arr << endl;
}