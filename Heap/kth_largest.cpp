#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pq; //MAX HEAP
        for(int idx = 0 ; idx < nums.size(); idx++)
        {
            pq.push(nums[idx]);
        }
        
        int ans;
        for(int idx1 = k ; idx1 > 0; idx1--) //K SE LEKE 0 TAK CHALAO JASE HI 0 HUA MATLAB HAMEI KTH LARGEST MIL GAYA KYUNKI MAX HEAP MAI TOP PE MAXIMUM HOGA USKO POP KARA FIR NEXT LARGEST FIR NEXT LARGEST FIR NEXT LARGEST POP KARTE JAO FIR KTH AA JAYEGA ACC TO LOOP
        {
            ans = pq.top(); //TOP PE HAMEHA PRIORITY VALA ELEMENT HO GA
            pq.pop();
        }
        
        return ans;
    }
};