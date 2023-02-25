//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
    {
        vector<int> ans;
        int i = 0, j = 0, maxi = INT_MIN;
        deque<int> q;
        while(j < n)
        {
            //Calculation part
            while(q.size() > 0 && arr[j] > q.back()) //arr[2] > 2 ? 3 > 2 yes
            {
                q.pop_back(); //queue se minimum ele pop karo and max elements push karo
                //pop 2
            }
            
            q.push_back(arr[j]); //q.push(3)
            
            //traversal part
            if(j - i + 1 < k) //2 - 0 +  1 < k ? 3 < 3 yes
            {
                j++; //slide till we don't hit the window //j++ = 2
            }
            
            //answer part
            else if(j - i + 1 == k) // 3 == 3 ? yes
            {
                ans.push_back(q.front()); //ans.push_back(3)
                if(arr[i] == q.front()) //arr[0] == 
                {
                    q.pop_front();
                }
                
                i++;
                j++;
            }
            
        }
        
        return ans;
        // your code here
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends