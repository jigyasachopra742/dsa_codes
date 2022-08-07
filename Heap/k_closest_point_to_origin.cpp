#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int,pair<int, int>>,  vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>> > pq; //min heap as we want the closest to origin
        
        //i is the row i = 0
        //suppose 1st row 1st column (x) = points[0][0]*points[0][0] = 1*1 = 1
        //suppose 1st row 2nd column (y) = points[0][1] * points[0][1]= 3*3 = 9
        //dist = 1 + 9 = 10
        
        //now i = 1 //2nd row
        //2nd row 1st column (x) = points[1][0] * points[1][0] = -2*-2 = 4
        //2nd row 2nd column (y) = points[1][1] * points[1][1] = 2*2 = 4
        //dist = 4 + 4 = 8
        //8 < 10 hence we considered [-2,2] as the answer

        for(int i = 0 ; i < points.size(); i++) //number of rows
        {
            int dist = points[i][0]* points[i][0] + points[i][1]*points[i][1]; //x*x + y*y
            pq.push({dist, {points[i][0], points[i][1]}}); //pair of distance and pair of corrdinates
        }
        
        vector<vector<int>> array; //2d array as ans
        while(k--) //jabtak k > 0 //ulta loop
        {
            pair<int,int> p = pq.top().second; //coordinates are stored as pair in p
            array.push_back({p.first, p.second}); //x and y coordinate
            pq.pop();
        }
        
        return array;
    }
};