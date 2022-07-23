#include<iostream>
using namespace std;

int parent[100000];
int rank[100000];

void makeset()
{
    for(int idx = 0; idx <= n; idx++)
    {
        //INITIALIZATION 
        parent[idx] = idx;
        rank[idx] = 0;
    }
}

void findPar(int node){ //HOW TO FIND A PARENT
    if(node == parent[node]) //if the node is himself the parent
    {
        return node;
    }

    return parent[node] = findPar(parent[node]); //path compression
}

void unionn(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }

    else if(rank[v] < rank[u]){
        parent[v] = u;
    }

    else{
        parent[v] = u; //level of tree increase
        rank[u]++;//height increases
    }
}

int main(){
    
    makeset();
    int m;

    cin >> m;
    while(m--){
        int u, v;
        union(u, v);
    }

    if(findPar(2) != findPar(3)){
        cout << "DIFFERENT COMPONENTS" << endl;
    }

    else{
        cout << "SAME COMPONENT" << endl;
    }

    return 0;
}