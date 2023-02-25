#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) 
{
   vector<long long> ans;
   queue<long long> q;
   
   
   long long i=0;
   long long j=0;
   
   while(j<N){
       if(A[j]<0){
           q.push(A[j]); //queue mai only negative elements are pushed
       }
       if(j-i+1<K){
           j++;
       }
       else if(j-i+1==K){
           if(q.empty()){ //agar empty matlab no negative ele in queue
               ans.push_back(0);
           }
           else{
               ans.push_back(q.front()); //pushing the 1st negative
               if(A[i]==q.front()){
                   q.pop(); //to make the queue empty so that new elemets can be pushed
               }
           }
           i++;
           j++;
       }
       
   }
   return ans;

 

                        
 }