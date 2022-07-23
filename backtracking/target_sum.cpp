#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> array)
{ 
    for(int idx = 0 ; idx < array.size() ; idx++)
    {
        if(idx == array.size() - 1)
        {
            cout << array[idx] << ", .";
        }
        else
        {
            cout << array[idx] << ", ";
        }
    }
    

    cout << "
";

}

void printTargetSumSubsets(vector<int> array , vector<int> ans , int sum , int idx , int target)
{
    
    if(sum > target)
    {
        return;
    }
    
    if(idx == array.size())
    {
        if(sum == target)
        {
            display(ans);
            
        }
        
        return;
    }
    
    
    ans.push_back(array[idx]); 
    
    printTargetSumSubsets(array , ans , sum + array[idx], idx + 1 , target); //ek baar sum mai add karo
    
    ans.pop_back();
    
    printTargetSumSubsets(array , ans , sum , idx + 1 , target); //vapis aate hue mat karo
    
}


int main()
{
    int size , target;

    cin >> size;
    
    vector<int> ans;
    
    vector<int> array;
    
    for(int idx = 0 ; idx < size ; idx++)
    {
       int idx2;
       
       cin >> idx2;
       
       array.push_back(idx2);
    }
    
    cin >> target;
    
    printTargetSumSubsets(array , ans , 0 , 0 , target);
    
    return 0;

}