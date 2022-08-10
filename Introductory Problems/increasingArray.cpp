#include<iostream>
using namespace std;
int main(){
    long long n,x,anterior,moves=0;
    cin>>n;
    cin>>anterior;
    for(int i=1; i<n; i++){
        cin>>x;
        if(x<anterior){
            moves += anterior-x;
        }
        else anterior = x;
    }
    cout<<moves;
    return 0;
}
