#include<iostream>
#include<algorithm>
using namespace std; 

int memo[502][502], visitados[502][502];

int cortes(int a, int b){
    if(a==b) return 0;
    if(visitados[a][b]) return memo[a][b];
    
    memo[a][b] = 10000;
    for(int i=1; i<a; i++){
        memo[a][b] = min(memo[a][b] , 1 + cortes(i,b) + cortes(a-i,b));
    }
    for(int i=1; i<b; i++){
        memo[a][b] = min(memo[a][b] , 1 + cortes(a,i) + cortes(a,b-i));
    }
    visitados[a][b] = 1;

    //cout<<"memo[a][b]: "<<a<<" "<<b<<" "<<memo[a][b]<<endl;
    return memo[a][b];
}

int main(){
    int a, b; 
    cin>>a>>b;
    cout<<cortes(a,b);
}