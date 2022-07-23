#include<iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf) 
{
    
    if(sc == dc && sr == dr)
    {
        cout << psf << endl;
        return;
    }
    
    if(sc < dc)     //horizontal
    {
        for(int hori = 1 ; hori <= dc - sc ; hori++)
        {
            printMazePaths(sr , sc + hori , dr , dc , psf + "h" + to_string(hori));
        }
            
    }
    
    if(sr < dr)     //vertical
    {
        for(int ver = 1 ; ver <= dr - sr ; ver++)
        {
            printMazePaths(sr + ver , sc , dr , dc , psf + "v" + to_string(ver));
        }
    
    }
    
    if(sr < dr && sc < dc)
    {
        for(int dia = 1 ; dia <= dc - sc && dia <= dr - sr ; dia++)
        {    
            printMazePaths(sr + dia , sc + dia , dr , dc , psf + "d" + to_string(dia));
        }
    }
}

int main() 
{
    int n ;
        
    int m ;
        
    cin>>n>>m;
        
    printMazePaths(0, 0, n - 1, m - 1, "");
}