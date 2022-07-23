void solve(vector<int> &num, vector<int> &arr, int sum, int idx)
{
    if(idx == num.size())
    {
        arr.push_back(sum);
        return;
    }
    
        solve(num, arr, sum + num[idx], idx + 1); //ek baar sum dala
        solve(num, arr, sum, idx + 1);//ek baar sum nahi dala
}


vector<int> subsetSum(vector<int> &num)
{
        vector<int> arr;
    
        solve(num, arr, 0, 0);
        sort(arr.begin(), arr.end());
        return arr;
        
    }
    // Write your code here.
