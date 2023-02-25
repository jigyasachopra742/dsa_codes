#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int j = 0;
        long long sum = 0, maxi = 0 , i = 0;
        unordered_map<int, int> mp; 
        while(j < nums.size())
        {//sum = 1
            sum+= nums[j]; //keep on calculating the sum on the way
            mp[nums[j]]++; //distinct ele 
            if(j - i + 1 < k) //keep on calculating the sum till we don't hit the win
            {
                j++; //as we keep on incrementing, we keep on adding arr[j] in sum
            }
            //map will store distinct ele and map size == k
            else if(j - i + 1 == k)
            {
                if(mp.size() == k) maxi = max(maxi, sum);
                sum-=nums[i];
                mp[nums[i]]--; //because we want to slide map as well
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
                j++;
            }
        }

        return maxi;
    }
};

/* 
    sum = 1;
    1->1
    0 - 0 +1 < 3 ? 1 < 3 ? yes
    j++ = j = 1
    sum = 6;
    5->1
    1-0+1 < 3 ? 2 < 3 ? yes
    j++ = j = 2
    sum = 10
    4->1
    2 - 0 + 1 < 3 ? 3 < 3 ? no
    2 - 0 + 1 == 3 ? 3 == 3 ? yes window size hit now calculate max sum
    mp => [1, 5, 4] = size = 3
    3 == 3 ? yes
    maxi = max(0, 10) = 10
    maxi = 10
    sum = 10 - nums[i] = 10 - nums[0] = 10-1 = 9
    sum = 9 that is equal to 5+4
    mp[nums[0]]-- => mp[1]-- => 0 (no longer used)
    i++ => i = 1
    j++ => j = 3 (now nums[3] = 2 will be included in sum so 5 + 4 + 2 = 11)


*/