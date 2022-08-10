#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int main(){
    int c, x;
    cin>>c>>x;
    vector<int> coins(c);
    for(int i=0; i<c; i++) cin>>coins[i];
    vector<int> respuestas;
    respuestas.resize(x+2,1000001);
    respuestas[0] = 0;
    for(int i=1; i<=x; i++){
        for(auto ci: coins){
            if(ci<=i){
                respuestas[i] = min(respuestas[i],respuestas[i-ci]+1);
            }
        }
    }
    if(respuestas[x]==1000001) cout<<-1;
    else cout<<respuestas[x];
    return 0;
} 
