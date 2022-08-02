#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicates(int *a, int size)
{
    vector<int> output;
    
    unordered_map<int, bool> seen;
    
    for(int idx = 0; idx < size; idx++)
    {
        if(seen.count(a[idx]) > 0) //returns either 0 or 1
        {
            continue; //if is already in hashmap then continue , do not push in array output
        }

        seen[a[idx]] = true; //if not, then mark it true
        output.push_back(a[idx]); //then push in an array
    }

    return output; //contains unique elements

}

int main()
{
    int a[] = {1,2,3,3,2,1,4,3,6,5,5};
    
    vector<int>output = removeDuplicates(a, 11);
    
    for(int idx = 0 ; idx < output.size(); idx++)
    {
        cout << output[idx] << endl; //prints unique elements
    }
}