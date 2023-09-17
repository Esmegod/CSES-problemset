#include<iostream>
using namespace std;

const int MAX = 1010;
bool visitados[MAX][MAX];
char tablero[MAX][MAX];
int n, m, x=0;


void discover(int i, int j){
    if(tablero[i][j]=='#' || visitados[i][j]) return;  
    visitados[i][j] = true;
    if(i-1>=0) discover(i-1, j);
    if(i+1<n) discover(i+1, j);
    if(j-1>=0) discover(i, j-1);
    if(j+1<m) discover(i, j+1);
}

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>tablero[i][j]; 


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tablero[i][j]=='#' || visitados[i][j]) continue; 
            x++;
            discover(i,j);
        }
    }
    
    cout<<x<<"\n"; 

    return 0;
}