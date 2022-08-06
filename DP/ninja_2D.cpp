#include <bits/stdc++.h>
using namespace std;

int solve(int curr_day, int last_task, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    //we are starting from last day going to 0
    if(curr_day == 0)
    {
        int maxi = 0;
        for(int task = 0; task < 3; task++) //current tasks loop
        {
            if(task != last_task)
            {
                int point = points[0][task]; //0th day pe prev pe nahi jaayega
                maxi = max(maxi, point);
            }
        }
        
        return dp[curr_day][last_task] = maxi; //from this if condition
    }
    
    if(dp[curr_day][last_task] != -1)
    {
        return dp[curr_day][last_task];
    }
    int maxi = 0; //for next days
    for(int task = 0; task < 3; task++)
    {
        if(task != last_task) //last task should not be equal to curr task
        {
            int point = points[curr_day][task] + solve(curr_day - 1, task, points, dp);
            //picking that day with that task and going to prev day with that task so that the prev
            //task does not take the similar consecutive task
            maxi = max(maxi, point);
        }
    }
    
    return dp[curr_day][last_task] = maxi;
}




int ninjaTraining(int n, vector<vector<int>> &points)
{
    //size is already defined in ques N*3 that is why there 3 columns for 3 tasks
    // 0 1 2 => tasks
   //here 2 parametres are changing current day and last day task
    vector<vector<int>> dp(n + 1, vector<int>(4, -1)); //4 tasks
    //0 task : all tasks have been perforemd
    //1 task : 1 taks is remaining
    //2 tasks : 2 tasks are remaining
    //3 tasks : none of the tasks have been performed yet
    
    return solve(n - 1, 3, points, dp);
    // Write your code here.
}